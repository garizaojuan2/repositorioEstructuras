/*
 * Autores: Juan Sebastián Garizao Puerto y Kevin Peréz
 * Fecha: 05 de mayo de 2023
 * Implementación TAD Colas de Prioridad
*/




#include <iostream>
#include <list>

#ifndef COLASDEPRIORIDAD_H
#define COLASDEPRIORIDAD_H

using namespace std;
typedef int Elemento;

class ColasDePrioridad
{
private:
	list<int> cola;
public:
	ColasDePrioridad(); // constructor colas de prioridad
	void enqueue(Elemento elem);// añade un elemento a la cola
	void deque(); // elimina el menor elemento de la cola
	int front(); // retorna el menor elemento de la cola
	bool empty(); // retorna un booleano que indica si la cola está vacía o no
};


#endif