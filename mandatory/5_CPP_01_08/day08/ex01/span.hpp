#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>

class Span {
	public:
		Span(void);
		Span(unsigned const& N);
		Span(Span const& cpy);
		~Span(void);

		Span&	operator=(Span const& op);
		int		getN(void) const;
		void	viewTab(void);
		void	addNumber(unsigned const& add);
		int		shortestSpan(void);
		int		longestSpan(void);

		class	UnsuccessfulAddException : public std::exception {
			public :
				const char*	what(void) const throw();
		};

		class	ImpossibleSpanException : public std::exception {
			public :
				const char* what(void) const throw();
		};


	private:
		unsigned int		_N;
		std::vector<int>	_tab;
};

#endif
