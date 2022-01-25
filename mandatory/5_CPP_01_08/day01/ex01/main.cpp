#include "Zombie.hpp"

int main()
{
	std::cout << "Creating new horde of Zombie... " << std::endl;
	Zombie *testZombie = zombieHorde(5, "Grrrrr");
	std::cout << "Pointer to the first zombieHorde: " << testZombie << std::endl;

	std::cout << "Deleting the horde pf zombie... " << std::endl;
	zombieHordeDelete(testZombie);
	return (0);
}