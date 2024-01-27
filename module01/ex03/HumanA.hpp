#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon	*arma;
public:
	HumanA(std::string str, Weapon *w);
	~HumanA();
	void	attack();
};

#endif
