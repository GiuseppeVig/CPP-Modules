#include "Array.hpp"
#include <iostream>

int main() {
    try {
        // Default Constructor Test
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Parameterized Constructor Test
        Array<int> intArray(5);
        std::cout << "Size of intArray: " << intArray.size() << std::endl;

        // Modify elements
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }

        // Print modified elements
        std::cout << "intArray contents: ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Copy Constructor Test (Deep Copy)
        Array<int> copiedArray = intArray;
        copiedArray[0] = 99; // Modify copied array

        std::cout << "Copied array contents: ";
        for (unsigned int i = 0; i < copiedArray.size(); i++) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Original intArray after modifying copy: ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Assignment Operator Test
        Array<int> assignedArray;
        assignedArray = intArray;
        assignedArray[1] = 42; // Modify assigned array

        std::cout << "Assigned array contents: ";
        for (unsigned int i = 0; i < assignedArray.size(); i++) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Original intArray after modifying assigned copy: ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Out-of-Bounds Access Test
        std::cout << "Trying to access out-of-bounds index... " << std::endl;
        std::cout << intArray[10] << std::endl; // Should throw exception

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
