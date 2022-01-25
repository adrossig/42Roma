#include "Karen.hpp"

Karen::Karen(void) {};

Karen::~Karen(void) {};

void    Karen::complain(std::string level) {
	int select = 0;

	select = (level.compare("DEBUG") == 0) ? 1 : select; 
	select = (level.compare("INFO") == 0) ? 2 : select;
	select = (level.compare("WARNING") == 0) ? 3 : select;
	select = (level.compare("ERROR") == 0) ? 4 : select;
	switch (select) {
		case 1: this->_debug(); 
		case 2: this->_info();
		case 3: this->_warning();
		case 4: this->_error(); break;
		default: {
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		}
	}
}

void    Karen::_debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my" 
		<< " 7XL-double-cheese-triple-pickle-special-ketchup"
		<< " burger. I just love it!" << std::endl;
	std::cout << std::endl;
}

void    Karen::_info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost"
		<< " more money. You don’t put enough! If you did I"
		<< " would not have to ask for it!" << std::endl;
	std::cout << std::endl;
}

void    Karen::_warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."
		<< " I’ve been coming here for years and you just started"
		<< " working here last month." << std::endl;
	std::cout << std::endl;
}

void    Karen::_error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak"
		<< " to the manager now." << std::endl;
	std::cout << std::endl;
}