#include "Span.hpp"
#include <algorithm>
#include <climits>

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
    if (v.size() + (unsigned int)(last - first) > N)
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
	
	std::vector<int> sorted = v;
	std::sort(sorted.begin(), sorted.end());
	
	int min = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; ++i) {
		int diff = sorted[i + 1] - sorted[i];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan()
{
	if(v.size() < 2)
		throw MinElements();
	
	return *std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end());
}

