#include "Karen.hpp"

int	main(int ac, char **av) {
	Karen	karenTest;

	if (ac != 2) {
		std::cout << "[ERROR]: Usage ./karenFilter argument" << std::endl;
		return (1);
	}
	karenTest.complain(av[1]);
	return (0);
}