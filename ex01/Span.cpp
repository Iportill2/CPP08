#include "Span.hpp"

Span::Span()
{
}
Span::Span(unsigned int n)
{
	N = n;

}
Span::~Span()
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

}
void Span::printVector()
{
	size_t i =0;
	std::cout << "Vector contain: ";
	while(i < v.size())
	{
        std::cout << v[i] << " ";
		i++;
	}
    std::cout << std::endl;
}
void Span::addNumber(unsigned int n)
{
	if(v.size() == N)
		throw MaxElements();
    v.push_back(n);
}
void Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
    if (v.size() + (unsigned int)(last - first) - 1 >= N)
	{
        throw MaxElements();
	}
	while (first != last) 
	{
		v.push_back(*first);
		++first;
	}
}
int Span::shortestSpan()
{
	if(v.size() < 2)
		throw MinElements();
	int min = compareMin();
	std::cout << "min = " ; 
	return(min);
}
int Span::longestSpan()
{
	if(v.size() < 2)
		throw MinElements();
	int max = compareMax();
	std::cout << "max = " ;
	return(max);
}
int Span::compareMax()
{
	size_t i = 0;
	int temp = 0;
	int max = 0;
	while (i < v.size() && v[i+1])
	{        
		temp = std::abs(v[i] - v[i+1]);
        if (temp > max)
        {
            max = temp;
        }
/* 		std::cout << v[i] << "x" << v[i+1] << std::endl;
		std::cout << "[max]" << max << std::endl; */

		i++;
	}
	return(max);
}

int Span::compareMin()
{
	size_t i = 0;
	int temp = 0;
	int min = std::numeric_limits<int>:: max() ;

	while (i < v.size() && v[i+1])
	{        
		temp = std::abs(v[i] - v[i + 1]);
        if (temp < min)
        {
            min = temp;
        }
/* 		std::cout << v[i] << "|" << v[i+1] << std::endl;
		std::cout << ">min<" << min << std::endl; */
		i++;
	}
	return(min);
}
