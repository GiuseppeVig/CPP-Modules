#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->setType(name);
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string arg)
{
	this->type = arg;
}

std::string	Weapon::getType()
{
	return this->type;
}
