
#include "easyfind.hpp"

int	main()
{
    // Agregar elementos a la pila

	//stack (no nos vale para iterar)
    std::stack<int> s;
	//map (no nos vale para iterar)
	std::map<int, int> m;




	//list
	std::list<int> l;
	//Double-Ended QUEue
	std::deque<int> d;
	//Vector
	std::vector<int> v;

	// Usando el método insert
	m.insert(std::pair<int, int>(1, 100)); // Inserta el par (1, 100)
	m.insert(std::make_pair(2, 200)); // Inserta el par (2, 200)

	// Usando el operador []
	m[3] = 300; // Inserta el par (3, 300)
	m[4] = 400; // Inserta el par (4, 400)
	// Imprimir elementos del mapa
	std::cout << "map elements: ";
	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it) 
    	std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;

	// Insertar elementos al final del vector
	for (int i = 1; i <= 5; ++i)
    	v.push_back(i);

	// Acceder a todos los elementos en un vector usando iterador
	std::cout << "Vector elements: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    	std::cout << *it << " ";
	std::cout << "\n";


	std::cout << "************************************" << std::endl; 
	std::cout << " >>> v.erase(v.begin() + 3);  <<<" << std::endl;
	std::cout << "************************************" << std::endl; 
	// Borrar un elemento en la posición especificada
	v.erase(v.begin() + 3);
	

	// access all elements in a vector using iterator
    std::cout << "Vector elements: ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    //	Insert an element before the specified position
	v.insert(v.begin() + 2, 10);
	std::cout << "Vector elements 'v.insert(v.begin() + 2, 10)': ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
    std::cout << "\n";

    // Erase an element at specified position
    v.erase(v.begin() + 3);
	std::cout << "Vector elements 'v.erase(v.begin() + 3)': ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    	std::cout << *it << " ";


    std::cout << "\n";
    std::cout << "\n";

	
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);

	d.push_back(11);
	d.push_back(21);
	d.push_back(31);
	d.push_back(41);
	d.push_back(51);

	//m.insert(7);

	s.push(9);
    s.push(8);
    s.push(7);


	std::cout << "\ndeque elements: ";
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it)
    	std::cout << *it << " ";
	std::cout << "\nlist elements: ";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
    	std::cout << *it << " ";
    // Imprimir y eliminar el elemento superior
	std::cout << "\nelementos dentro del stack:" ;
    while (!s.empty()) 
	{
        std::cout << ' ' << s.top();
        s.pop();
	}
	std::cout << std::endl;
	try
	{
		std::cout << std::endl << "list in position 5 is = " << *easyfind(l, 5) << std::endl;
		std::cout << "deque in position 3 is = " << *easyfind(d, 3) << std::endl;
		//std::cout << "map in position 3 is = " << *easyfind(m,1) << std::endl;
		//std::cout << "stack in position = " << *easyfind(s, 1) << std::endl;
		std::cout << "vector in position 3 is = " << *easyfind(v, 3) << std::endl;
		std::cout << "vector in position 6 is = " << *easyfind(v, 6) << std::endl;//exception
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	return (0);
}
