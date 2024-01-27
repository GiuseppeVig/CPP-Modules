#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *bob = new Zombie();
	bob->setName(name);
	return (bob);
}
