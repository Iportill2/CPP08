#ifndef SPAN_HPP
# define SPAN_HPP
# include <stack>
# include <vector>
# include <iostream>

class Span
{
	private:
		std::vector<int> s;
		unsigned int nbr;
		int n;
		int max;
		int min;
	public:

		Span();
		Span(unsigned int n);
		~Span();

void	printVector();
void	compareAndSet();

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