#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// Template function iter that applies a function to each element of an array
template <typename T>
void iter(T* array, size_t length, void (*func)(T&)) {
    if (!array || !func) return; // Safety check
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif
