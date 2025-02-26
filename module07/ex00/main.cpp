#include "whatever.hpp"
#include <iostream>

int main() {
    int a = 5, b = 10;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    std::cout << "Min of (3, 7): " << min(3, 7) << std::endl;
    std::cout << "Max of (3, 7): " << max(3, 7) << std::endl;

    double x = 4.2, y = 4.2;
    std::cout << "Min of (4.2, 4.2): " << min(x, y) << std::endl;
    std::cout << "Max of (4.2, 4.2): " << max(x, y) << std::endl;

    std::string str1 = "Hello", str2 = "World";
    std::cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    swap(str1, str2);
    std::cout << "After swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;

    std::cout << "Min of (\"apple\", \"banana\"): " << min(std::string("apple"), std::string("banana")) << std::endl;
    std::cout << "Max of (\"apple\", \"banana\"): " << max(std::string("apple"), std::string("banana")) << std::endl;

    return 0;
}