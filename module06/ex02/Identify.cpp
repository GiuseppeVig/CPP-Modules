#include "Base.hpp"
#include <cstdlib> // For rand()
#include <ctime>   // For time()

Base* generate(void) {
    std::srand(std::time(0)); // Seed the random generator
    int random = std::rand() % 3; // Generate 0, 1, or 2

    if (random == 0) {
        std::cout << "Generated A" << std::endl;
        return new A();
    } else if (random == 1) {
        std::cout << "Generated B" << std::endl;
        return new B();
    } else {
        std::cout << "Generated C" << std::endl;
        return new C();
    }
}

#include "Base.hpp"

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer Type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer Type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer Type: C" << std::endl;
    else
        std::cout << "Pointer Type: Unknown" << std::endl;
}


void identify(Base& p) {
    try {
        (void) dynamic_cast<A&>(p);
        std::cout << "Reference Type: A" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void) dynamic_cast<B&>(p);
        std::cout << "Reference Type: B" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void) dynamic_cast<C&>(p);
        std::cout << "Reference Type: C" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    std::cout << "Reference Type: Unknown" << std::endl;
}

