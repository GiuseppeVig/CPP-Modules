#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>  // For std::find
#include <iterator>   // For iterator operations
#include <exception>  // For std::exception
#include <iostream>   // For std::cout

// Exception class for element not found
class NotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Element not found!";
    }
};

// Function template to find an integer in a container
template <typename T>
typename T::iterator easyfind(T& container, int target) {
    typename T::iterator it = std::find(container.begin(), container.end(), target);
    if (it == container.end())
        throw NotFoundException();
    return it;
}

#endif
