#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    std::cout << "==== MutantStack Test ====" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating over stack elements:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    for (; it != ite; ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "\n==== Comparison with std::list ====" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Iterating over list elements:" << std::endl;
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    for (; lit != lite; ++lit) {
        std::cout << *lit << std::endl;
    }

    return 0;
}
