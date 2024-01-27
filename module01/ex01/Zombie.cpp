#include "Zombie.hpp"

void	Zombie::setName(std::string str)
{
	name = str;
}

std::string	Zombie::getName()
{
	return name;
}
Zombie::Zombie(void)
{
	this->name = "unnamed";
};

Zombie::Zombie(std::string name)
{
	this->name = name;
};

Zombie::~Zombie(void){
	std::cout<<name<<" Is dead!"<<std::endl;
}

void	Zombie::announce()
{
	std::cout<< name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}



