#include "Zombie.hpp"

Zombie::Zombie(void) {};

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is dead." << std::endl;
}

void Zombie::nameZombie(std::string name)
{
	this->_name = name;
}

void Zombie::announce(void)
{
	std::cout << this->_name << "  BraiiiiiiinnnzzzZ..." << std::endl;
}