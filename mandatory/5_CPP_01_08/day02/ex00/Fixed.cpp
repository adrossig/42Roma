#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
	this->_num = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}

// Operators
Fixed &Fixed::operator=(const Fixed &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_num = assign.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "\e[0;31mgetRawBits member function called\e[0m" << std::endl;
	return (this->_num);
}

void Fixed::setRawBits(int const raw)
{
	this->_num = raw;
}
