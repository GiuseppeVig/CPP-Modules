#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->name = "FragTrap";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout<<name<<" FragTrap has entered the Arena, FIGHT!"<<std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout<<name<<" FragTrap has entered the Arena, FIGHT!"<<std::endl;
}

FragTrap::~FragTrap()
{
	std::cout<<name<<" Has been fragged"<<std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap()
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout<<name<<" FragTrap has entered the Arena, FIGHT!"<<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		this->name = other.name;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout<<name<<" Has one Frag Left to win the Game...High Fives for the WINNER "<<name<<" FRAGTRAP"<<std::endl;
}