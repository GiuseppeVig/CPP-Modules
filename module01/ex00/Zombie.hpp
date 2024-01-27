#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string name;
public:
	void		setName(std::string str);
	std::string	getName();
	void		announce(void);
	Zombie(void);
	~Zombie(void);
	Zombie(std::string name);
};

void	announce(void);
Zombie* newZombie(std::string name);
void	randomChump( std::string name );

#endif
