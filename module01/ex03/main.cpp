#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
		Weapon sword = Weapon("Claymore");
		HumanA bob("Bob", &sword);
		bob.attack();
		sword.setType("some other type of sword");
		bob.attack();
		Weapon gun = Weapon("Glock");
		HumanB jim("Jim");
		jim.setWeapon(&gun);
		jim.attack();
		gun.setType("some other type of gun");
		jim.attack();
}
