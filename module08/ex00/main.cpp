#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

void testVector() {
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i * 2); // Fill with even numbers

    try {
        std::vector<int>::iterator it = easyfind(vec, 6);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        easyfind(vec, 7); // Not present
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testList() {
    std::list<int> lst;
    for (int i = 1; i <= 5; i++)
        lst.push_back(i * 10); // Fill with multiples of 10

    try {
        std::list<int>::iterator it = easyfind(lst, 30);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        easyfind(lst, 25); // Not present
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testDeque() {
    std::deque<int> deq;
    for (int i = 0; i < 7; i++)
        deq.push_back(i + 1);

    try {
        std::deque<int>::iterator it = easyfind(deq, 5);
        std::cout << "Found in deque: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        easyfind(deq, 10); // Not present
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Testing vector:" << std::endl;
    testVector();
    
    std::cout << "\nTesting list:" << std::endl;
    testList();

    std::cout << "\nTesting deque:" << std::endl;
    testDeque();

    return 0;
}
