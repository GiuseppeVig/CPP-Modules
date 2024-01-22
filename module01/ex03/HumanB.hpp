#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon	arma;
public:
	HumanB(std::string str);
	~HumanB();
	void	attack();
};

HumanB::HumanB(std::string str)
{
	name = str;
}

HumanB::~HumanB()
{
}


#endif
