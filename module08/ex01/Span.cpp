#include "Span.hpp"

// Constructor
Span::Span(unsigned int N) : maxSize(N) {}

// Copy Constructor
Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize) {}

// Assignment Operator
Span &Span::operator=(const Span &other) {
    if (this != &other) {
        numbers = other.numbers;
        maxSize = other.maxSize;
    }
    return *this;
}

// Destructor
Span::~Span() {}

// Add single number
void Span::addNumber(int n) {
    if (numbers.size() >= maxSize)
        throw FullSpanException();
    numbers.push_back(n);
}

// Add multiple numbers using iterators
void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (numbers.size() + std::distance(begin, end) > maxSize)
        throw FullSpanException();
    numbers.insert(numbers.end(), begin, end);
}

// Compute shortest span
int Span::shortestSpan() const {
    if (numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

// Compute longest span
int Span::longestSpan() const {
    if (numbers.size() < 2)
        throw NoSpanException();
    return *std::max_element(numbers.begin(), numbers.end()) - *std::min_element(numbers.begin(), numbers.end());
}
