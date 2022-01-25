#include "Zombie.hpp"

int main()
{
	std::cout << "Creating new Zombie" << std::endl;
	Zombie *testZombie = newZombie("Grrrrr");
	testZombie->announce();
	delete testZombie;

	std::cout << "Creating randomChump" << std::endl;
	randomChump("Brrrrr");
	return (0);
}