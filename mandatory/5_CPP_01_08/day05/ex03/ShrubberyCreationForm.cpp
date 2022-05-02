#include "ShrubberyCreationForm.hpp"

//Constructor

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("default", 145, 137) {
	this->_signed = false;
	this->setTarget("default");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& name): Form(name, 145, 137) {
	this->_signed = false;
	this->setTarget(this->getName());
}

//Constructor By Copy

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& cpy) {
	*this = cpy;
}

//Destructor

ShrubberyCreationForm::~ShrubberyCreationForm(void) {};

//Exceptions

const char*				ShrubberyCreationForm::CreationDeclined::what() const throw() {
	return ("[ ERROR ]: Shrubbery creation form declined, form not signed.");
}

const char*				ShrubberyCreationForm::CreationApprouved::what() const throw() {
	return ("[ SUCCES ]: Shrubbery creation form approuved.");
}


//Member Function

void 					ShrubberyCreationForm::setTarget(std::string const& target) {
	this->_target = target;
}

std::string const&		ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}

void					ShrubberyCreationForm::execute(Bureaucrat const& executor) {
	if (this->getSigned() == false)
		throw ShrubberyCreationForm::CreationDeclined();
	else if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	else {
		std::ofstream	file(this->getName() + "_shrubbery", std::ios::out);
		std::string		content =  "";
		content += "    __-–__\n";
		content += "  _/~      \\_ __-__\n";
		content += " /        ~~  \\    \\_\n";
		content += "|  ~~          |    ~~\\\n";
		content += " \\_        ~~_/       |\n";
		content += "   \\__ ~~ __/_  ~~  _/\n";
		content += "       |  |   \\_  _/\n";
		content += "       |  |    |  |\n";
		content += "       |  |    |  |\n";
		content += "      /    \\   /   \\\n";
		content += "~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		file << content << std::endl;
		file.close();
		throw  ShrubberyCreationForm::CreationApprouved();
	}
}

//Operator Equal

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& op) {
	if (this != &op) {
		this->_signed = op._signed;
		this->setTarget(op.getTarget());
	}
	return (*this);
}

