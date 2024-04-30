#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <stack>

class Span
{
	private:
		std::stack<int> s;
		unsigned int s;
		int n;
	public:

		Span();
		Span(int n);
		~Span();

	void addNumber(int n);
	int shortestSpan();
	int longestSpan();
};
#endif

/*
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_vec;
		std::vector<int>	_vecOrdered;
	
	public:
		Span();
		Span(unsigned int N);
		Span(Span const & src);
		~Span();

		Span &	operator=(Span const & rhs);

		void	addNumber(unsigned int n);
		int		shortestSpan();
		int		longestSpan();
		void	printVec();
		void	printVecOrd();

};

#endif


*/