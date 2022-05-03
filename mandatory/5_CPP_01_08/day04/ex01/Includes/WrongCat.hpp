#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : virtual public WrongAnimal{
	public:
		WrongCat(void);
		WrongCat(WrongCat const& cpy);
		~WrongCat(void);

		WrongCat&	operator=(WrongCat const& op);
		void		makeSound(void) const;
};

#endif
