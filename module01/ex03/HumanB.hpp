#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon	*arma;
public:
	HumanB(std::string str);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon *arma);
};

#endif
