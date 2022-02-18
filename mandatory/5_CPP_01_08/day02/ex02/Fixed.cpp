#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	//std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
	this->_num = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
	*this = copy;
}

Fixed::Fixed(int const n)
{
	//std::cout << "\e[0;33mInt Constructor called of Fixed\e[0m" << std::endl;
	this->_num = n << this->_bit;
}

Fixed::Fixed(float const n)
{
	//std::cout << "\e[0;33mFloat Constructor called of Fixed\e[0m" << std::endl;
	this->_num = (int)roundf(n * (1 << this->_bit));
}

// Destructor
Fixed::~Fixed()
{
	//std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}

// Operators
Fixed &Fixed::operator=(const Fixed &assign)
{
	//std::cout << "Assignation operator called" << std::endl;
	this->_num = assign.getRawBits();
	return *this;
}

Fixed Fixed::operator+(const Fixed &assign)
{
	return Fixed(this->toFloat() + assign.toFloat());
}

Fixed Fixed::operator-(const Fixed &assign)
{
	return Fixed(this->toFloat() - assign.toFloat());
}
Fixed Fixed::operator*(const Fixed &assign)
{
	return Fixed(this->toFloat() * assign.toFloat());
}

Fixed Fixed::operator/(const Fixed &assign)
{
	return Fixed(this->toFloat() / assign.toFloat());
}

bool Fixed::operator==(const Fixed &assign)
{
	return (this->toFloat() == assign.toFloat() ? true : false);
}

bool Fixed::operator!=(const Fixed &assign)
{
	return (this->toFloat() != assign.toFloat() ? true : false);
}

bool Fixed::operator>(const Fixed &assign)
{
	return (this->toFloat() > assign.toFloat() ? true : false);
}

bool Fixed::operator<(const Fixed &assign)
{
	return (this->toFloat() < assign.toFloat() ? true : false);
}

bool Fixed::operator<=(const Fixed &assign)
{
	return (this->toFloat() <= assign.toFloat() ? true : false);
}

bool Fixed::operator>=(const Fixed &assign)
{
	return (this->toFloat() >= assign.toFloat() ? true : false);
}

Fixed &Fixed::operator++(void)
{
	this->_num++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->_num--;
	return (*this);
}

Fixed Fixed::operator++(int inc)
{
	(void)inc;
	Fixed result = (*this);
	++(*this);
	return (result);
}

Fixed Fixed::operator--(int dec)
{
	(void)dec;
	Fixed result = (*this);
	--(*this);
	return (result);
}

// Getters && Setters
int Fixed::getRawBits(void) const
{
	//std::cout << "\e[0;31mgetRawBits member function called\e[0m" << std::endl;
	return (this->_num);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "\e[0;31msetRawBits member function called\e[0m" << std::endl;
	this->_num = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_num / (1 << this->_bit));
}

int Fixed::toInt(void) const
{
	return (this->_num >> this->_bit);
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
	return (n1.toFloat() < n2.toFloat() ? n1 : n2);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
	return (n1.toFloat() < n2.toFloat() ? n2 : n1);
}

const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2)
{
	return (n1.toFloat() < n2.toFloat() ? n1 : n2);
}

const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2)
{
	return (n1.toFloat() < n2.toFloat() ? n2 : n1);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	return (os << fixed.toFloat());
}
