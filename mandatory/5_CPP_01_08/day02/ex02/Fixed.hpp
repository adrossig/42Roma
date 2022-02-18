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

		Fixed &operator=(const Fixed&assign);
		Fixed operator+(const Fixed&assign);
		Fixed operator-(const Fixed&assign);
		Fixed operator*(const Fixed&assign);
		Fixed operator/(const Fixed&assign);

		bool operator==(const Fixed&assign);
		bool operator!=(const Fixed&assign);
		bool operator>(const Fixed&assign);
		bool operator<(const Fixed&assign);
		bool operator<=(const Fixed&assign);
		bool operator>=(const Fixed&assign);

		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int inc);
		Fixed operator--(int dec);

		static Fixed &min(Fixed &n1, Fixed &n2);
		static Fixed &max(Fixed &n1, Fixed &n2);
		static const Fixed &min(const Fixed &n1, const Fixed &n2);
		static const Fixed &max(const Fixed &n1, const Fixed &n2);

	private:
		static const int _bit = 8;
		int _num;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);

#endif
