#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string>

class Weapon
{
private:
	std::string type;
public:
	void		setType(std::string arg);
	std::string	getType();
	Weapon(std::string name);
	~Weapon();
};

#endif
