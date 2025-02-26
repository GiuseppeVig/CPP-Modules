#include "iter.hpp"
#include <iostream>
#include <string>

// Function to print an element
template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

// Function to increment an integer
void increment(int& n) {
    n += 1;
}

// Function to convert a string to uppercase (for std::string)
void toUppercase(std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        str[i] = std::toupper(str[i]);
    }
}

int main() {
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intSize, printElement);
    std::cout << std::endl;

    iter(intArray, intSize, increment);

    std::cout << "Incremented int array: ";
    iter(intArray, intSize, printElement);
    std::cout << std::endl;

    // Test with an array of strings
    std::string strArray[] = {"hello", "world", "templates"};
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original string array: ";
    iter(strArray, strSize, printElement);
    std::cout << std::endl;

    iter(strArray, strSize, toUppercase);

    std::cout << "Uppercased string array: ";
    iter(strArray, strSize, printElement);
    std::cout << std::endl;

    // Test with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Original double array: ";
    iter(doubleArray, doubleSize, printElement);
    std::cout << std::endl;

    return 0;
}
