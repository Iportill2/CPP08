#include "Span.hpp"
/* 
Should output:
$> ./ex01
2
14
$>
*/

void subjectTest() 
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		//sp.addNumber(12);
		std::cout << "//////////////////////////////\n";
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl; 
		std::cout << "//////////////////////////////\n";
		sp.printVector();//funcion para ver el contenido del vector
		std::cout << "//////////////////////////////\n";
    }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}
void ownTest() 
{
/* 	sp.addNumber(4294967294); */
	try
	{

        // Crear un vector de enteros
        std::vector<int> nbr;
        nbr.push_back(1);
        nbr.push_back(2);
        nbr.push_back(3);
        nbr.push_back(4);
        nbr.push_back(5);

        // Crear un objeto de la clase Span
        Span sp(nbr.size());

        // Añadir los números del vector al objeto Span
        sp.addNumber(nbr.begin(),nbr.end());

        // Imprimir el rango más corto y más largo
		std::cout << "*****************************\n";
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
		std::cout << "*****************************\n";
		sp.printVector();
		std::cout << "*****************************\n";
    }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


int main() 
{

	std::cout << "Subject" << std::endl;
	subjectTest();

	std::cout << std::endl;
	std::cout << "OwnTest" << std::endl;
	ownTest();


}


