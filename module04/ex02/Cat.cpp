#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    brain = new Brain();
}

Cat::~Cat()
{
    delete brain;
}

Cat::Cat(const Cat& other) : Animal()
{
    this->type = other.type;
}

Cat &Cat::operator=(const Cat& other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout<<"Meooooooooooooow"<<std::endl;
}