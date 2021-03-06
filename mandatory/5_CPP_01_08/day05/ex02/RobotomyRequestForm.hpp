#ifndef ROBOTOMYREQUESTFROM_HPP
# define ROBOTOMYREQUESTFROM_HPP
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const& name);
		RobotomyRequestForm(RobotomyRequestForm const& cpy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm&	operator=(RobotomyRequestForm const& op);
		void					setTarget(std::string const& target);
		std::string const&		getTarget(void) const;
		void					execute(Bureaucrat const& executor);

		class RequestDeclined: public std::exception {
            public:
                const char* what() const throw();
        };

		class RequestDeclinedSign: public std::exception {
            public:
                const char* what() const throw();
        };

        class RequestApprouved : public std::exception {
            public:
                const char* what() const throw();
        };

	private:
		std::string		_target;
};

#endif
