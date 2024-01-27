#include "Zombie.hpp"

int	main(void)
{
	Zombie *a = new Zombie("Ed");
	Zombie *c = newZombie("Edd");
	a->announce();
	c->announce();
	delete a;
	delete c;
	randomChump("Eddy");
}
