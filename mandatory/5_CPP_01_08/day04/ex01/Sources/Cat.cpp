#include "../Includes/Cat.hpp"

//Constructor

Cat::Cat(void) {
    this->setType("Cat");
    this->_brain = new Brain();
    for (int idx = 0; idx < 100; idx += 1)
        this->_brain->setIdeas("", idx);
    std::cout << "Class Cat Initialized" << std::endl;
}

//Constructor By Copie

Cat::Cat(Cat const& cpy) {
    std::cout << "Class Cat Initialized By Copy" << std::endl;
    *this = cpy;
}

//Destructor

Cat::~Cat(void) {
    delete this->_brain;
    std::cout << "Class Cat Destroyed" << std::endl;
}

//Member Functions

void        Cat::makeSound(void) const {
    std::cout << "** Miaooouuuu... **" << std::endl;
}

Brain*      Cat::getBrain(void) const {
    return (this->_brain);
}

//Equal Operator

Cat&     Cat::operator=(Cat const& op) {
    if (this != &op) {
        this->_type = op._type;
        this->_brain->operator=(*op._brain);
    }
    return (*this);
}
