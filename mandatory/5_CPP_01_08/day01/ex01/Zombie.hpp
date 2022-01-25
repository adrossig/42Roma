#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
	public:

		void	announce();
		void	nameZombie(std::string name);
		Zombie(void);
		~Zombie(void);

	private:

		std::string	_name;
};

Zombie	*newZombie(std::string name);
Zombie	*zombieHorde(int N, std::string name);
void	randomChump(std::string name);
void    zombieHordeDelete(Zombie *zombieHorde);

#endif