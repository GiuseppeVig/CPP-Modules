#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept> // For std::exception

template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;

public:
    // Default constructor: Creates an empty array
    Array() : _array(NULL), _size(0) {}

    // Constructor with size parameter: Creates an array of `n` elements
    Array(unsigned int n) : _array(new T[n]()), _size(n) {} // Value-initialized

    // Copy constructor: Creates a deep copy
    Array(const Array& other) : _array(NULL), _size(0) {
        *this = other;
    }

    // Assignment operator: Ensures deep copy
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _array; // Clean up existing memory
            _size = other._size;
            _array = new T[_size]; // Allocate new memory
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i]; // Copy elements
        }
        return *this;
    }

    // Destructor: Frees allocated memory
    ~Array() {
        delete[] _array;
    }

    // Subscript operator for element access (with bounds checking)
    T& operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _array[index];
    }

    // Const version of operator[]
    const T& operator[](unsigned int index) const {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _array[index];
    }

    // Returns the size of the array
    unsigned int size() const {
        return _size;
    }
};

#endif
