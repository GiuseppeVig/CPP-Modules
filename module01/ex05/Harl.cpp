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
	levels[1].lv = "INFO";
	levels[1].func = &Harl::info;
	levels[2].lv = "WARNING";
	levels[2].func = &Harl::warning;
	levels[3].lv = "ERROR";
	levels[3].func = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::complain(std::string level)
{
	int i = 0;
	while (i < 4)
	{
		if (this->levels[i].lv == level)
		{
			(this->*levels[i].func)();
			break;
		}
		else 
			i++;
	}
}
