#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template< typename T>
void	swap(T& elem1, T& elem2) {
	T	tmp = elem1;
	elem1 = elem2;
	elem2 = tmp;
}

template< typename T>
T const&	min(T const& elem1, T const& elem2) {
	return ((elem1 < elem2) ? elem1 : elem2);
}

template< typename T>
T const&	max(T const& elem1, T const& elem2) {
	return ((elem1 > elem2) ? elem1 : elem2);
}

#endif
