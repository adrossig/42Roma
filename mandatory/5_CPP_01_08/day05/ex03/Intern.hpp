#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(Intern const& cpy);
		~Intern(void);

		Intern&		operator=(Intern const& op);
		Form*		makeForm(std::string const& formType, std::string const& formTarget);

		class MakeFormDeclined : public std::exception {
			public:
				char const*	what() const throw();
		};

};

#endif
