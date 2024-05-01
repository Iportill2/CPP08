#ifndef SPAN_HPP
# define SPAN_HPP
# include <stack>
# include <vector>
# include <iostream>
# include <limits>

class Span
{
	private:
			Span();
			unsigned int N;
			std::vector<int> v;

/* 			int min;
			int max; */
	public:

			Span(unsigned int n);
	Span &	operator=(const Span & other);
			Span(const Span &copy);
			~Span();

	void	printVector();
	int		compareMax();
	int		compareMin();

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

/*
#include "Span.hpp"

Span::Span(unsigned int n): N(n)
{
	//std::cout << "Span default constructor called" << std::endl;
}

Span::~Span(void)
{

}

Span & Span::operator=(const Span & other)
{
	if (this == &other)
    	return *this;
    N = other.N;
    v = other.v;
    return *this;
}

Span::Span(const Span &copy): N(copy.N), v(copy.v)
{
	//std::cout << "Span copy constructor called" << std::endl;
}

void Span::addNumber(int n)
{
	if (v.size() == N)
    	throw MaxElements();
    v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
    if (v.size() + (unsigned int)(last - first) - 1 >= N)
        throw MaxElements();
    for (;first != last; first++)
        v.push_back(*first);
}

long int Span::shortestSpan()
{	
	if (v.size() < 2)
    	throw MinElements();
    std::vector<long int> sortedVec(v);
    std::sort(sortedVec.begin(), sortedVec.end());
    long int i = 1;
    int size = sortedVec.size();
    long int res;
    res = sortedVec[i] - sortedVec[i - 1];
    while (i < size)
    {
    	if (sortedVec[i] - sortedVec[i - 1] < res)
    		res = sortedVec[i] - sortedVec[i - 1];
    	i++;
    }
    return res;
}

long long int Span::longestSpan()
{
	if (v.size() < 2)
    	throw MinElements();
    std::vector<long int> sortedVec(v);
    std::sort(sortedVec.begin(), sortedVec.end());
    int size = sortedVec.size() - 1;
    long int res = sortedVec[size] - sortedVec[0];
    return (res);
}
*/


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