#include "../Includes/Dog.hpp"

//Constructor

Dog::Dog(void) {
    this->setType("Dog");
    std::cout << "Class Dog Initialized" << std::endl;
}

//Constructor By Copie

Dog::Dog(Dog const& cpy) {
    std::cout << "Class Dog Initialized By Copy" << std::endl;
    *this = cpy;
}

//Destructor

Dog::~Dog(void) {
    std::cout << "Class Dog Destroyed" << std::endl;
}

//Member Functions

void        Dog::makeSound(void) const {
    std::cout << "** Waouuuffff... **" << std::endl;
}

//Equal Operator

Dog&     Dog::operator=(Dog const& op) {
    if (this != &op)
        this->_type = op._type;
    return (*this);
}
