#include "Zombie.hpp"

Zombie* newZomvie(std::string name)
{
	Zombie *bob = new Zombie();
	bob->setName(name);
	return (bob);
}
