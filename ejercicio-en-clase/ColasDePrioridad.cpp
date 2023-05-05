/*
 * Autores: Juan Sebastián Garizao Puerto y Kevin Peréz
 * Fecha: 05 de mayo de 2023
 * Implementación TAD Colas de Prioridad
*/

#include "ColasDePrioridad.h"

ColasDePrioridad::ColasDePrioridad(){}

void ColasDePrioridad::enqueue(Elemento elem){
		cola.push_back(elem);
}

void ColasDePrioridad::deque(){
	list<int>::iterator it = cola.begin(), menor = cola.begin();
	it++;
	while(it != cola.end())
	{
		if((*it) < (*menor))
			menor = it;		
		it++;
	}
	cola.erase(menor);


}

int ColasDePrioridad::front(){
	int ans;
	list<int>::iterator it = cola.begin(), menor = cola.begin();
	it++;
	while(it != cola.end())
	{
		if((*it) < (*menor))
			menor = it;		
		it++;
	}
	ans = (*menor);
	return ans;
}

bool ColasDePrioridad::empty(){
	return cola.empty();
}