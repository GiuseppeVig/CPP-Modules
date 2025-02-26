#include "BitcoinExchange.hpp"

// Constructor
BitcoinExchange::BitcoinExchange() {}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Load the Bitcoin price database from CSV
void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, priceStr;
        if (std::getline(ss, date, ',') && std::getline(ss, priceStr)) {
            float price = std::atof(priceStr.c_str());
            prices[date] = price; // Store in map
        }
    }
}

// Get the Bitcoin price for a given date (or closest lower date)
float BitcoinExchange::getBitcoinPrice(const std::string &date) const {
    std::map<std::string, float>::const_iterator it = prices.lower_bound(date);
    
    if (it == prices.end()) {
        return (--it)->second; // Last available price
    }
    if (it->first == date) {
        return it->second; // Exact match
    }
    if (it == prices.begin()) {
        throw std::runtime_error("Error: no available price data.");
    }
    return (--it)->second; // Closest lower date
}

// Validate date format (YYYY-MM-DD)
bool BitcoinExchange::isValidDate(const std::string &date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    int year, month, day;
    std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    return (year >= 2009 && month >= 1 && month <= 12 && day >= 1 && day <= 31);
}

// Validate value (float or positive integer, 0-1000)
bool BitcoinExchange::isValidValue(const std::string &value) const {
    char *end;
    float num = std::strtof(value.c_str(), &end);
    return (*end == '\0' && num >= 0.0f && num <= 1000.0f);
}

// Process input file and display results
void BitcoinExchange::processInputFile(const std::string &filename) const {
    std::ifstream file(filename.c_str());
    if (!file) {
        throw std::runtime_error("Error: could not open input file.");
    }

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, valueStr;
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            date.erase(date.find_last_not_of(" ") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" "));

            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            if (!isValidValue(valueStr)) {
                std::cerr << "Error: invalid value => " << valueStr << std::endl;
                continue;
            }

            float value = std::atof(valueStr.c_str());
            try {
                float rate = getBitcoinPrice(date);
                std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
            } catch (std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        } else {
            std::cerr << "Error: invalid format => " << line << std::endl;
        }
    }
}
