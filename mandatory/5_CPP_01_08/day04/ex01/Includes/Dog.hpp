#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : virtual public Animal {
	public:
		Dog(void);
		Dog(Dog const& cpy);
		~Dog(void);

		Dog&		operator=(Dog const& op);
		void		makeSound(void) const;
		Brain*		getBrain(void) const;

	private:
		Brain*  _brain;
};

#endif
