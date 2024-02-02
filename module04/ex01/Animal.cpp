#include "Animal.hpp"

Animal::Animal()
{
    type = "Undefined";
}

Animal::~Animal()
{
}

Animal::Animal(const Animal& other)
{
    this->type = other.type;
}

Animal &Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string Animal::getType(void) const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout<<"*Animal Sounds*"<<std::endl;
}