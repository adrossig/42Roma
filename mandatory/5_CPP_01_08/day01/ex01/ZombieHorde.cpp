#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::string copy = name;
		zombieHorde[i].nameZombie(copy += std::to_string(i));
		zombieHorde[i].announce();
	}
	return (zombieHorde);
}

void    zombieHordeDelete(Zombie *zombieHorde)
{
	delete [] zombieHorde;
}