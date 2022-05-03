#include "../Includes/WrongAnimal.hpp"

//Constructor

WrongAnimal::WrongAnimal(void) {
	this->setType("Default");
	std::cout << "Class WrongAnimal Initialized" << std::endl;
}

//Constructor By Copie

WrongAnimal::WrongAnimal(WrongAnimal const& cpy) {
	std::cout << "Class WrongAnimal Initialized By Copy" << std::endl;
	*this = cpy;
}

//Destructor

WrongAnimal::~WrongAnimal(void) {
	std::cout << "Class WrongAnimal Destroyed" << std::endl;
}

//Member Functions

void        WrongAnimal::setType(std::string type) {
	this->_type = type;
}

std::string WrongAnimal::getType(void) const {
	return (this->_type);
}

void        WrongAnimal::makeSound(void) const {
	std::cout << "** Wrong default... **" << std::endl;
}

//Equal Operator

WrongAnimal&     WrongAnimal::operator=(WrongAnimal const& op) {
	if (this != &op)
		this->_type = op._type;
	return (*this);
}
