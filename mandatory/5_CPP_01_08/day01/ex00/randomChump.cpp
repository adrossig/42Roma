#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie *randomChump = newZombie(name);
	randomChump->announce();
	delete randomChump;
}