#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    std::vector<int> numbers;
    unsigned int maxSize;

public:
    // Constructors & Destructor
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    // Methods
    void addNumber(int n);
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan() const;
    int longestSpan() const;

    // Exception Classes
    class FullSpanException : public std::exception {
        const char *what() const throw() { return "Error: Span is full!"; }
    };

    class NoSpanException : public std::exception {
        const char *what() const throw() { return "Error: Not enough elements to calculate span!"; }
    };
};

#endif
