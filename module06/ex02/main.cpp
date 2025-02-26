#include "Base.hpp"

int main() {
    Base* obj = generate();

    std::cout << "Identifying by Pointer:" << std::endl;
    identify(obj);

    std::cout << "Identifying by Reference:" << std::endl;
    identify(*obj);

    delete obj; // Prevent memory leak
    return 0;
}
