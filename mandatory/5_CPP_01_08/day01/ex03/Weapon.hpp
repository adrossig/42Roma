#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
	public: 
		std::string const getType(void) const;
		void setType(std::string type);

		Weapon(std::string type);
		~Weapon(void);
	private:
		std::string _type;

};

#endif