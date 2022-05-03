#include "Convert.hpp"

int		main(int ac, char **av) {

	if (ac != 2) {
		ac > 2 ? std::cerr << "[ ERROR ]: Too many arguments." << std::endl :
			std::cerr << "[ ERROR ]: Not enough arguments.";
		return (1);
	}
	convert(av[1]);
	return (0);
}
