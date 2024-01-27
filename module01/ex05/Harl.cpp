#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout<<"DEBUG: chitevvivo"<<std::endl;
}

void	Harl::info(void)
{
	std::cout<<"INFO: chitevviecchio"<<std::endl;
}

void	Harl::warning(void)
{
	std::cout<<"WARNING: kitemmuort"<<std::endl;
}

void	Harl::error(void)
{
	std::cout<<"ERROR: kitestramuort"<<std::endl;
}

Harl::Harl()
{
	levels[0].lv = "DEBUG";
	levels[0].func = &Harl::debug;
	levels[0].lv = "INFO";
	levels[0].func = &Harl::info;
	levels[0].lv = "WARNING";
	levels[0].func = &Harl::warning;
	levels[0].lv = "ERROR";
	levels[0].func = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::complain(std::string level)
{
	static int i = -1;
	if (i <= 3)
		level == levels[++i].lv ? (this->*levels[i].func)() : complain(level) ;
	i = -1;
}
