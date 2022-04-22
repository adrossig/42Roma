#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &cpy);
		~FragTrap(void);

		FragTrap &operator=(FragTrap const &op);
		void announce(void) const;
		void highFivesGuys(void);
};

#endif
