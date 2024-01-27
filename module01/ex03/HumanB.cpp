#include "HumanB.hpp"

HumanB::HumanB(std::string str)
{
	this->name = str;
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << arma->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon *arma)
{
	this->arma = arma;
}
