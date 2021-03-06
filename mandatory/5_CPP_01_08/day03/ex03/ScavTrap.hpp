#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &cpy);
		~ScavTrap(void);

		ScavTrap &operator=(ScavTrap const &op);
		bool const &getGateKeeperMode(void) const;
		void guardGate(void);
		void announce(void) const;

	protected:
		bool _gateKeeperMode;
};

#endif
