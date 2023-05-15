#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;


int main(){
	int patients, commands, cases = 1, number, tam;
	cin >> patients;
	cin >> commands;
	char letter;
	list<pair<int,int>> ::iterator itF;
	map<int, int>::iterator itM;
	while(patients != 0 && commands != 0){
		list<pair<int,int>> fila;
		pair<int,int> pareja;
		map<int, int> mapa;
		tam = (patients < commands) ? patients : commands;
		cout << "Case " << cases << ":" << endl;
		for(int i = 1; i <= tam; i++){
			pareja.first = i;
			pareja.second = 0;
			fila.push_back(pareja);
			mapa[i] = 0;

		}

		for(int i = 0; i < commands; i++){ // se ejecuta n + 1 veces donde n es el número de comandos
			cin >> letter; // se ejecuta n veces
			if(letter == 'N'){ // en el mejor caso se ejecuta n veces y en el peor ninguna
				itF = fila.begin(); // en el mejor caso se ejecuta n veces y en el peor ninguna
				while(itF != fila.end()){ // en el mejor caso se ejecuta 2 veces y en el peor ninguna
					if(mapa.at((*itF).first) == (*itF).second){// en el mejor caso esta parte se ejecuta log(m) veces, donde m es el número de pacientes y en el peor ninguna
						cout << ((*itF).first) << endl;// en el mejor caso esta parte se ejecuta 1 vez y en el peor ninguna
						fila.push_back((*itF));// en el mejor caso esta parte se ejecuta 1 vez y en el peor ninguna
						itF = fila.end();// en el mejor caso esta parte se ejecuta 1 vez y en el peor ninguna
					}
					else // en el mejor caso no se ejecuta y en el peor tampoco
						itF++;
					fila.pop_front(); // se ejecuta 1 vez
				}
			}
			else if(letter == 'E'){ // en el peor caso se ejecuta n veces y en el mejor ninguna
				cin >> number;c
				itM = mapa.find(number); // se ejecuta en el peor caso n*log(m) y en el mejor ninguna
				if(itM == mapa.end()) // en el peor caso se ejecuta n veces y en el mejor ninguna
					mapa[number] = 0; // en el peor caso se ejecuta n veces y en el mejor ninguna
				else // no se ejecuta ni en el mejor ni en el peor caso
					mapa[number] += 1; // no se ejecuta ni en el mejor ni en el peor caso
				pareja.first = number; // se ejecuta n veces en el peor caso y en el mejor ninguna
				pareja.second = mapa.at(number); // se ejecuta n * log(m) veces en el peor caso y en el mejor ninguna
				fila.push_front(pareja); //se ejecuta n veces en el peor caso y en el mejor ninguna
			}
		}
		cin >> patients;
		cin >> commands;
		cases += 1;
	}
	return 0;
	
}

/* El mejor caso se da cuando todas las ordenes son N y el primer elemento de la lista, es válido para ser impreso
 * El peor caso se da cuando todas las órdenes son E y el iterador del mapa, da como resultado mapa.end(), es decir que recorre todo el mapa
 * En el peor caso tiene complejidad O(n*log(m)) y en el mejor O(log(m))
 */