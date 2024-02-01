#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap *clap = new ClapTrap("Steve");
    ClapTrap b;
    b = *clap;
    int i;
    i = 10;
    while (i-- > 5)
        clap->attack("Psycho");
    clap->takeDamage(5);
    while (i-- > -1)
        clap->beRepaired(1);
    clap->attack("Psycho");
    clap->beRepaired(1);
    b.attack("Psycho");
    b.beRepaired(10);
    b.takeDamage(15);
    delete clap;
    return (0);
}