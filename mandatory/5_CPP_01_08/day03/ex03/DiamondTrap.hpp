#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &cpy);
		~DiamondTrap(void);

		DiamondTrap &operator=(DiamondTrap const &op);
		void setName(std::string const &name);
		std::string const &getName(void) const;
		void announce(void) const;
		void whoAmI(void);

	private:
		std::string _name;
};

#endif
