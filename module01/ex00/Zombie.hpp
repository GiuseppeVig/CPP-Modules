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
	Zombie();
	~Zombie(){
	std::cout<<name<<" Is dead!"<<std::endl;
	}
};

void	announce(void);

#endif
