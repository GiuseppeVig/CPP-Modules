#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ~ClapTrap();
    ClapTrap(const ClapTrap &other);
    ClapTrap& operator=(const ClapTrap &other);
    void    setName(std::string name);
    std::string getName(void);
    void    attack(const std::string &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};

#endif