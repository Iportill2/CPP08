#include "easyfind.hpp"

int	main()
{
	// Test with vector
	std::vector<int> v;
	for (int i = 1; i <= 5; ++i)
		v.push_back(i);

	// Test with list
	std::list<int> l;
	for (int i = 10; i <= 50; i += 10)
		l.push_back(i);

	// Test with deque
	std::deque<int> d;
	for (int i = 11; i <= 51; i += 10)
		d.push_back(i);

	try
	{
		std::cout << "Vector contains 3: " << *easyfind(v, 3) << std::endl;
		std::cout << "List contains 30: " << *easyfind(l, 30) << std::endl;
		std::cout << "Deque contains 31: " << *easyfind(d, 31) << std::endl;
		std::cout << "Vector contains 6: " << *easyfind(v, 6) << std::endl; // Should throw
	}
	catch (std::exception &e)
	{
		std::cout << "Element not found" << std::endl;
	}
	return (0);
}
