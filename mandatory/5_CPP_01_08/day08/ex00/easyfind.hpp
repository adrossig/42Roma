#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>

template<typename T>
bool easyfind(T& elem, int const find) {
	for (typename T::iterator itT = elem.begin(); itT != elem.end(); itT++)
		if (*itT == find)
			return (true);
	return (false);
}

#endif
