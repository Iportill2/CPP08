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
        throw MaxElements();
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
		std::cout << v[i] << "x" << v[i+1] << std::endl;
		std::cout << "[max]" << max << std::endl;

		i++;
	}
	return(max);
}

int Span::compareMin()
{
	int i = 0;
	int temp = 0;
	int min = std::numeric_limits<int>:: max() ;

	int vsize = v.size();
	vsize = vsize - 1;

	while (i < vsize)
	{        
		temp = std::abs(v[i] - v[i + 1]);
        if (temp < min)
        {
            min = temp;
        }
		std::cout << v[i] << "|" << v[i+1] << std::endl;
		std::cout << ">min<" << min << std::endl;
		i++;
	}
	return(min);
}


































/*
#include "Span.hpp"
#include <ctime>

Span::Span() : _N(0) 
{
	throw (std::exception());
}

Span::Span(unsigned int N) : _N(N)
{
	if (N < 2)
		throw (std::exception());
	srand(time(NULL));
	for (unsigned int i = 0; i < N; i++)
		this->_vec.push_back(rand() % 100000);
	this->_vecOrdered = this->_vec;
	std::sort(this->_vecOrdered.begin(), this->_vecOrdered.end());

}

Span::Span(Span const & src) : _N(src._N), _vec(src._vec) {}

Span::~Span() {}

Span &	Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		this->_N = rhs._N;
		this->_vec = rhs._vec;
	}
	return *this;
}

void	Span::addNumber(unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
		this->_vec.push_back(rand() % 100000);
	this->_vecOrdered = this->_vec;
	std::sort(this->_vecOrdered.begin(), this->_vecOrdered.end());
}

int		Span::shortestSpan()
{
	return (this->_vecOrdered[1] - this->_vecOrdered[0]);
}

int		Span::longestSpan()
{
	return (this->_vecOrdered.back() - this->_vecOrdered.front());
}

void	Span::printVec()
{
	for (unsigned int i = 0; i < this->_vec.size(); i++)
		std::cout << this->_vec[i] << " ";
	std::cout << std::endl;
}

void	Span::printVecOrd()
{
	for (unsigned int i = 0; i < this->_vecOrdered.size(); i++)
		std::cout << this->_vecOrdered[i] << " ";
	std::cout << std::endl;
}
*/