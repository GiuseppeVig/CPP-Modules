#include "Zombie.hpp"

void	Zombie::setName(std::string str)
{
	name = str;
}

std::string	Zombie::getName()
{
	return name;
}

void	Zombie::announce()
{
	std::cout<< name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}


