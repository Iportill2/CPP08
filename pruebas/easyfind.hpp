#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <stack>
/*
La biblioteca <stack> en C++ es una biblioteca 
de contenedores adaptadores que proporciona la 
funcionalidad de una estructura de datos de tipo 
pila (stack). Una pila es una estructura de datos 
que sigue el principio de LIFO (Last In, First Out), 
lo que significa que el último elemento que se añade 
a la pila es el primero en ser eliminado.

Aquí hay algunas operaciones comunes que puedes 
realizar con un std::stack:

push: Agrega un elemento en la parte superior de la pila.
pop: Elimina el elemento superior de la pila.
top: Accede al elemento superior de la pila.
empty: Comprueba si la pila está vacía.
size: Devuelve el número de elementos en la pila.
*/
# include <map>
/*
La biblioteca <map> en C++ es una biblioteca de 
contenedores que proporciona la funcionalidad de 
un mapa, que es una colección de pares clave-valor 
donde cada clave es única. Los elementos en un 
std::map están siempre ordenados por su clave.

Aquí hay algunas operaciones comunes que puedes 
realizar con un std::map:

insert: Inserta un par clave-valor en el mapa.
erase: Elimina un elemento del mapa por su clave.
find: Busca un elemento en el mapa por su clave.
operator[]: Accede al valor asociado con una clave.
*/
# include <algorithm>//std::sort,std::find,std::count,std::replace,std::shuffle...etc
/*
La biblioteca <algorithm> en C++ no es una función, 
sino una biblioteca estándar que proporciona una 
serie de funciones para realizar ciertas operaciones 
en rangos de elementos. Estas operaciones incluyen cosas 
como ordenar, buscar, manipular y contar elementos.

Algunas de las funciones más comunes proporcionadas 
por <algorithm> incluyen:

std::sort: Ordena los elementos en un rango.
std::find: Busca un valor en un rango.
std::count: Cuenta el número de veces que un 
valor aparece en un rango.
std::replace: Reemplaza todas las instancias de 
un valor en un rango por otro valor.
std::shuffle: Reordena aleatoriamente los elementos 
en un rango.
*/
# include <vector>//vectores
/*
La biblioteca <vector> en C++ es una biblioteca 
de contenedores que proporciona la funcionalidad 
de un array dinámico. A diferencia de los arrays 
normales, los vectores pueden cambiar de tamaño, 
con sus elementos almacenados en memoria contigua.

Aquí hay algunas operaciones comunes que puedes 
realizar con un std::vector:

push_back: Agrega un elemento al final del vector.
pop_back: Elimina el último elemento del vector.
size: Devuelve el número de elementos en el vector.
at: Accede a un elemento en una posición específica.
begin y end: Devuelven iteradores al principio y 
al final del vector, respectivamente.
*/
# include <list>//listas
/*
La biblioteca <list> en C++ es una biblioteca de 
contenedores que proporciona la funcionalidad de 
una lista doblemente enlazada. Las listas son secuencias 
de elementos en las que cada elemento tiene conexiones 
a su elemento anterior y siguiente.

Aquí hay algunas operaciones comunes que puedes 
realizar con un std::list:

push_back: Agrega un elemento al final de la lista.
push_front: Agrega un elemento al frente de la lista.
pop_back: Elimina el último elemento de la lista.
pop_front: Elimina el primer elemento de la lista.
size: Devuelve el número de elementos en la lista.
begin y end: Devuelven iteradores al principio y 
al final de la lista, respectivamente.
*/
# include <deque>//Double-Ended QUEue
/*
La biblioteca <deque> en C++ es una biblioteca 
de contenedores que proporciona la funcionalidad 
de una cola de doble extremo. deque es un acrónimo 
de Double Ended Queue.

Un deque es similar a un vector, pero permite 
inserciones y eliminaciones eficientes tanto en el 
frente como en la parte trasera del contenedor. Esto 
es diferente a un vector, que solo permite inserciones 
y eliminaciones eficientes en la parte trasera.
*/

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::exception();
	return (it);
}

#endif 

