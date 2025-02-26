#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdlib>

class ScalarConverter {
public:
    static void convert(const std::string &input) {
        // Attempt conversion to char
        if (input.length() == 1 && std::isprint(input[0])) {
            char charValue = input[0];
            std::cout << "char: '" << charValue << "'" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }

        // Attempt conversion to int
        int intValue = 0;
        std::stringstream ss(input);
        ss >> intValue;
        if (ss.fail() || !ss.eof()) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << intValue << std::endl;
        }

        // Attempt conversion to float
        float floatValue = 0.0f;
        ss.clear();
        ss.str(input);
        ss >> floatValue;
        if (ss.fail() || !ss.eof()) {
            std::cout << "float: impossible" << std::endl;
        } else {
            std::cout << "float: " << floatValue << "f" << std::endl;
        }

        // Attempt conversion to double
        double doubleValue = 0.0;
        ss.clear();
        ss.str(input);
        ss >> doubleValue;
        if (ss.fail() || !ss.eof()) {
            std::cout << "double: impossible" << std::endl;
        } else {
            std::cout << "double: " << doubleValue << std::endl;
        }
    }
};
