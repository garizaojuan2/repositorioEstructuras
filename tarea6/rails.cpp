#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	int tam, comb, num, i;

	vector<int> pos;
	bool flag;
	scanf("%d", &tam);
	while(tam != 0){
		scanf("%d",&comb);
		stack<int> inicial, mid, pilaClear; 
		while(comb != 0){ // se ejecuta n + 1 veces donde n es la cantidad de veces que se hace una combinación
			i = tam; // se ejecuta n veces donde n es la cantidad de veces que se hace una combinación
			inicial.push(i); // se ejecuta n veces donde n es la cantidad de veces que se hace una combinación
			pos.push_back(comb); // se ejecuta n veces donde n es la cantidad de veces que se hace una combinación
			i -= 1; // se ejecuta n veces donde n es la cantidad de veces que se hace una combinación
			while(i > 0){ // se ejecuta m veces, donde m es la cantidad de trenes

				scanf("%d",&num); // se ejecuta m - 1 veces, donde m es la cantidad de trenes
				inicial.push(i); // se ejecuta m - 1 veces, donde m es la cantidad de trenes
				pos.push_back(num); // se ejecuta m - 1 veces, donde m es la cantidad de trenes
				i -= 1;  // se ejecuta m - 1 veces, donde m es la cantidad de trenes
			}
			i = 0; // se ejecuta una vez
			flag = true;
			while(i < tam && flag){ // en el mejor caso se ejecuta tres veces y en el peor m + 1 veces

				
				if(!inicial.empty() && inicial.top() == pos[i]){ // en el mejor caso no se ejecuta y en el peor no se ejecuta
					i += 1; // en el mejor caso no se ejecuta y en el peor tampoco
					inicial.pop(); // en el mejor caso no se ejecuta y en el peor tampoco
				}
				else if(!mid.empty() && mid.top() == pos[i]){ // en el mejor caso no se ejecuta y en el peor se ejecuta m veces
					i += 1; // en el mejor caso no se ejecuta y en el peor se ejecuta m veces
					mid.pop(); // en el mejor caso no se ejecuta y en el peor se ejecuta m veces
				}
				else{
					if(!inicial.empty() && inicial.top() < pos[i]){ // en el peor caso se ejecuta m veces y en el mejor ninguna
						mid.push(inicial.top()); // en el peor caso se ejecuta m veces y en el mejor ninguna
						inicial.pop(); // en el peor caso se ejecuta m veces y en el mejor ninguna
					}
					else if(!mid.empty() && mid.top() > pos[i]){ // en el mejor caso se ejecuta una vez y en el peor no se ejecuta
						flag = false;// en el mejor caso se ejecuta una vez y en el peor no se ejecuta
					}
				}
			}
			if(flag)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			scanf("%d",&comb);
			pos.clear();
			inicial = pilaClear;
			mid = pilaClear;
		}
		scanf("%d", &tam);
		cout << endl;
	}
			
		

	
	return 0;
}

// Se puede denotar que el mejor caso se da cuando en alguno de los primeros números se da una contradicción y no se puede llegar a la combinación esperada
// El peor caso se da cuando todos los elementos están pero al revés en la combinación
// En el peor caso, el programa tiene como complejidad O(m) y en el mejor caso O(1)

//Nota: las complejidades están dadas sin tener en cuenta el proceso de lectura



