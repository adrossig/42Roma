#ifndef KAREN_H
#define KAREN_H

#include <iostream>
#include <unistd.h>

class Karen 
{
	public:
		Karen(void);
		~Karen(void);
		void	complain(std::string level);

	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
};

#endif