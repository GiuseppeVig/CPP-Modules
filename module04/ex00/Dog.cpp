#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
}

Dog::~Dog()
{
}

Dog::Dog(const Dog& other) : Animal()
{
    this->type = other.type;
}

Dog &Dog::operator=(const Dog& other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout<<"BARK BARK"<<std::endl;
}