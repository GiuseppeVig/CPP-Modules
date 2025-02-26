#include "Span.hpp"

int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // Testing exception: Adding beyond capacity
        try {
            sp.addNumber(42);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        // Testing exception: Not enough elements for span
        Span smallSpan(1);
        smallSpan.addNumber(42);
        try {
            std::cout << smallSpan.shortestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        // Testing with large range
        Span bigSpan(10000);
        std::vector<int> bigNumbers;
        for (int i = 0; i < 10000; i++) {
            bigNumbers.push_back(i * 3);
        }
        bigSpan.addRange(bigNumbers.begin(), bigNumbers.end());

        std::cout << "Big Span - Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big Span - Longest: " << bigSpan.longestSpan() << std::endl;
        
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
