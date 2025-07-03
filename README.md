# CPP Module 08 - Templated containers, iterators, algorithms

## 📋 Descripción General

Este módulo de C++ se centra en el uso de **contenedores templados**, **iteradores** y **algoritmos** de la STL (Standard Template Library). Los ejercicios están diseñados para familiarizarse con los conceptos fundamentales de la programación genérica en C++98.

## 🎯 Objetivos de Aprendizaje

- Uso de templates con contenedores STL
- Manejo de iteradores
- Implementación de algoritmos genéricos
- Creación de contenedores personalizados
- Manejo de excepciones en contextos templados

---

## 📁 Estructura del Proyecto

```
CPP08/
├── ex00/           # easyfind - Búsqueda en contenedores
├── ex01/           # Span - Análisis de rangos
├── ex02/           # MutantStack - Stack iterable
└── README.md       # Esta documentación
```

---

## 🔍 EJERCICIO 00: easyfind

### 📝 **Descripción**
Implementa una función template `easyfind` que busca un elemento en cualquier contenedor STL que soporte iteradores.

### 🎯 **Objetivo**
Crear una función genérica que funcione con diferentes tipos de contenedores (vector, list, deque, etc.).

### 📁 **Archivos**
- `easyfind.hpp` - Función template
- `main.cpp` - Pruebas y ejemplos
- `Makefile` - Compilación

### 🔧 **Implementación**
```cpp
template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::exception();
    return (it);
}
```

### ✅ **Características**
- Función template genérica
- Compatible con vector, list, deque
- Manejo de excepciones cuando no encuentra el elemento
- Uso de iteradores STL
- Usa `std::find` del header `<algorithm>`

### 🚀 **Uso**
```bash
cd ex00
make
./easy_find
```

### 📊 **Salida Esperada**
```
Vector contains 3: 3
List contains 30: 30
Deque contains 31: 31
Vector contains 6: Element not found
```

---

## 📏 EJERCICIO 01: Span

### 📝 **Descripción**
Implementa una clase `Span` que almacena hasta N enteros y puede calcular el span (rango) más corto y más largo entre todos los números almacenados.

### 🎯 **Objetivo**
Crear una clase que maneje colecciones de enteros y calcule estadísticas sobre las diferencias entre elementos.

### 📁 **Archivos**
- `Span.hpp` - Declaración de la clase
- `Span.cpp` - Implementación de la clase
- `main.cpp` - Pruebas y ejemplos
- `Makefile` - Compilación

### 🔧 **Implementación Principal**

#### **Constructor y Métodos Básicos**
```cpp
class Span {
private:
    unsigned int N;
    std::vector<int> v;

public:
    Span(unsigned int n);
    void addNumber(unsigned int n);
    void addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
    int shortestSpan();
    int longestSpan();
};
```

#### **Algoritmo shortestSpan()**
```cpp
int Span::shortestSpan() {
    if(v.size() < 2) throw MinElements();
    
    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());
    
    int min = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < min) min = diff;
    }
    return min;
}
```

#### **Algoritmo longestSpan()**
```cpp
int Span::longestSpan() {
    if(v.size() < 2) throw MinElements();
    return *std::max_element(v.begin(), v.end()) - 
           *std::min_element(v.begin(), v.end());
}
```

### ✅ **Características**
- Forma canónica ortodoxa completa
- Manejo de excepciones personalizadas
- Dos métodos de añadir números (individual y rango)
- Algoritmos eficientes para cálculo de spans
- Capacidad máxima configurable

### 🚀 **Uso**
```bash
cd ex01
make
./Span
```

### 📊 **Salida Esperada**
```
Subject
//////////////////////////////
2
14
//////////////////////////////

OwnTest
*****************************
1
4
*****************************
```

---

## 🔀 EJERCICIO 02: MutantStack

### 📝 **Descripción**
Implementa una clase `MutantStack` que hereda de `std::stack` pero añade la capacidad de iterar sobre sus elementos.

### 🎯 **Objetivo**
Crear un stack que mantenga toda su funcionalidad original pero que permita iteración como otros contenedores STL.

### 📁 **Archivos**
- `MutantStack.hpp` - Clase template
- `main.cpp` - Pruebas y comparación con std::list
- `Makefile` - Compilación

### 🔧 **Implementación**
```cpp
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {}
    MutantStack(const MutantStack<T>& src) : std::stack<T>(src) {}
    ~MutantStack() {}
    
    MutantStack<T>& operator=(const MutantStack<T>& rhs) {
        this->std::stack<T>::operator=(rhs);
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};
```

### ✅ **Características**
- Herencia de `std::stack<T>`
- Iteradores begin() y end() implementados
- Acceso al contenedor interno `c`
- Forma canónica ortodoxa completa
- Mantiene toda la funcionalidad de stack
- Compatible con algoritmos STL

### 🚀 **Uso**
```bash
cd ex02
make
./mutant_stack
```

### 📊 **Salida Esperada**
```
=== Test with MutantStack ===
Top: 17
Size: 1
Stack contents: 5 3 5 737 0 

=== Comparison with std::list ===
Back: 17
Size: 1
List contents: 5 3 5 737 0
```

---

## 🛠️ Compilación y Ejecución

### **Compilar todos los ejercicios:**
```bash
# Desde el directorio raíz CPP08
cd ex00 && make && cd ../ex01 && make && cd ../ex02 && make && cd ..
```

### **Ejecutar todos los ejercicios:**
```bash
cd ex00 && ./easy_find && cd ../ex01 && ./Span && cd ../ex02 && ./mutant_stack && cd ..
```

### **Limpiar todos los ejercicios:**
```bash
cd ex00 && make fclean && cd ../ex01 && make fclean && cd ../ex02 && make fclean && cd ..
```

---

## 📚 Conceptos Clave Aplicados

### **1. Templates (Plantillas)**
- Funciones template genéricas
- Clases template
- Especialización de tipos

### **2. Iteradores STL**
- `begin()` y `end()`
- Tipos de iteradores: `iterator` y `const_iterator`
- Compatibilidad con algoritmos STL

### **3. Algoritmos STL**
- `std::find` - Búsqueda en contenedores
- `std::sort` - Ordenamiento
- `std::max_element` / `std::min_element` - Búsqueda de extremos

### **4. Contenedores STL**
- `std::vector` - Array dinámico
- `std::list` - Lista doblemente enlazada
- `std::deque` - Cola de doble extremo
- `std::stack` - Pila LIFO

### **5. Manejo de Excepciones**
- Excepciones personalizadas
- `std::exception` base
- Manejo con try-catch

---

## ✅ Estándares de 42 Cumplidos

- ✅ **C++98 Standard**: Compatible con el estándar C++98
- ✅ **Forma Canónica Ortodoxa**: Constructor, destructor, copy constructor, operador de asignación
- ✅ **Headers Guards**: Protección contra inclusión múltiple
- ✅ **Compilación**: Sin warnings con -Wall -Wextra -Werror
- ✅ **Makefiles**: Reglas all, clean, fclean, re
- ✅ **Manejo de Memoria**: Sin leaks de memoria
- ✅ **Código Limpio**: Sin comentarios innecesarios

---

## 🎓 Evaluación

Este proyecto demuestra competencia en:

1. **Programación Genérica**: Uso efectivo de templates
2. **STL Mastery**: Dominio de contenedores, iteradores y algoritmos
3. **Diseño de Clases**: Implementación correcta de clases con funcionalidad avanzada
4. **Manejo de Excepciones**: Uso apropiado de excepciones en C++
5. **Algoritmos**: Implementación eficiente de algoritmos de búsqueda y cálculo

---

**Autor**
Iker Portillo
