#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>

class BitcoinExchange {
private:
    std::map<std::string, float> prices; // Stores Bitcoin prices (date -> price)

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);
    void processInputFile(const std::string &filename) const;
    float getBitcoinPrice(const std::string &date) const;
    bool isValidDate(const std::string &date) const;
    bool isValidValue(const std::string &value) const;
};

#endif
