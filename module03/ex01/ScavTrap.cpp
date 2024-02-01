#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->name = "ScavTrap";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout<<"I am "<<name<<" ScavTrap, i guard this gate right here"<<std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout<<"I am "<<name<<" the ScavTrap, i guard this gate right here"<<std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout<<"Goddamit, ya got me"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap()
{
    this->name = other.name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
        this->name = other.name;
    return (*this);
}

void    ScavTrap::guardGate(void)
{
    std::cout<<"Ain't nobody opening this gate while "<<name<<" the ScavTrap is on guard, NO SIR!"<<std::endl;
}