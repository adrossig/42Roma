#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain {
	public:
		Brain(void);
		Brain(Brain const& cpy);
		~Brain(void);

		Brain&	operator=(Brain const& op);
		void	setIdeas(std::string ideas, int idx);
		void	viewIdeas(void) const;

	private:
		std::string	_ideas[100];
};

#endif
