#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap *trap = new ScavTrap("Jones");
    int i;
    i = 50;
    while (i-- > 25)
        trap->attack("Psycho");
    trap->takeDamage(50);
    while (i-- > -1)
        trap->beRepaired(1);
    trap->guardGate();
    trap->attack("Psycho");
    trap->beRepaired(1);
    delete trap;
    return (0);
}