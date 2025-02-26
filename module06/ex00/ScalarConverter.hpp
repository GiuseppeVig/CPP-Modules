#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConverter {
private:
    ScalarConverter();  // Private constructor to prevent instantiation
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter(); // Destructor (added for Coplien's form)

public:
    static void convert(const std::string &input);
};
