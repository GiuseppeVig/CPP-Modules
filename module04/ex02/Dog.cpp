#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    brain = new Brain();
}

Dog::~Dog()
{
    delete brain;
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