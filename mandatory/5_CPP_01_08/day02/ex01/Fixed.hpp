#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(int const n);
		Fixed(float const n);

		// Destructor
		~Fixed();

		// Operators
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		Fixed &operator=(const Fixed &assign);

	private:
		static const int _bit = 8;
		int _num;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);

#endif
