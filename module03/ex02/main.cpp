#include "FragTrap.hpp"

int main(void)
{
    FragTrap *frag = new FragTrap("Jones");
    int i;
    i = 50;
    while (i-- > 25)
        frag->attack("Psycho");
    frag->takeDamage(50);
    while (i-- > -1)
        frag->beRepaired(1);
    frag->highFivesGuys();
    frag->attack("Psycho");
    frag->beRepaired(1);
    delete frag;
    return (0);
}