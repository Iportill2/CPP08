#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <exception>

class Span
{
	private:
		Span();
		unsigned int N;
		std::vector<int> v;
	public:

			Span(unsigned int n);
	Span &	operator=(const Span & other);
			Span(const Span &copy);
			~Span();

	void	printVector();
	void 	addNumber(unsigned int n);
	void	addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
	int 	shortestSpan();
	int 	longestSpan();

	class MaxElements: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("The span reached the maximum number of elements");
		}
	};
	class MinElements: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("The span need minum 2 elements");
		}
	};
};
#endif