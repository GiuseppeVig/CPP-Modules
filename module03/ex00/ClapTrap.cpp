#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    this->name = "ClapTrap";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout<<"Hi, i am ClapTrap, but you can call me "<<name<<std::endl;
}

ClapTrap::ClapTrap(std::string name)  
{
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout<<"Hi, i am ClapTrap, but you can call me "<<name<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    this->name = other.name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->name = other.name;
        hitPoints = 10;
        energyPoints = 10;
        attackDamage = 0;
        std::cout<<"Hi, i am ClapTrap, but you can call me "<<name<<std::endl;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout<<"ClapTrap "<<name<<" is now scrap metal, RIP"<<std::endl;
}

void    ClapTrap::setName(std::string name)
{
    this->name = name;
}

std::string ClapTrap::getName(void)
{
    return (name);
}

void    ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0)
    {
        std::cout<<"ClapTrap "<<name<<" attacks "<<target<<" for "<<attackDamage<<" points of damage "<<std::endl;
        std::cout<<"1 energy point spent"<<std::endl;
        energyPoints--;
    }
    else
        std::cout<<"ClapTrap "<<name<<" Has no energy points, so it can't act"<<std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout<<"ClapTrap "<<name<<" Has been hit for "<<amount<<" points of damage"<<std::endl;
    hitPoints -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0)
    {
        std::cout<<"ClapTrap "<<name<<" repairs itself for "<<amount<<" points of damage"<<std::endl;
        hitPoints += amount;
        std::cout<<"1 energy point spent"<<std::endl;
        energyPoints--;
    }
    else
        std::cout<<"ClapTrap "<<name<<" Has no energy points, so it can't act"<<std::endl;
}