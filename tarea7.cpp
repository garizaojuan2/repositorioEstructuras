#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <functional>

using namespace std;

// Punto 1
typedef int Elemento;

void eliminarPosicionesPila(stack<Elemento>& pil, list<int>& l){
    stack<Elemento> tmp;
    list<int>::iterator it = l.begin();
    int i = 0;
    if(!pil.empty() && !l.empty()){
    	while (it != l.end()){
        	if(i == (*it))
            	it++;
        	else
            	tmp.push(pil.top());
        	pil.pop();
    	}
    	while(!tmp.empty()){
        	pil.push(tmp.top());
        	tmp.pop();
    	}
	}
}
/* Esta operación tiene como complejidad O(n) donde n es el tamaño de la lista, esto se debe a que 
 * se recorre hasta el final de la lista y luego según el tamaño de la lista, se regresan los elementos a la pila
*/	

// Punto 6

int verificarRepetidos1(queue<Elemento>& col) {
    int i = 0;
    int ans = 0;
    queue<Elemento> tmp;
    map<Elemento, int> mapaReps;
    map<Elemento, int>::iterator it;
    while (!col.empty()) {
        it = mapaReps.find(col.front());
        if (it != mapaReps.end())
            ans += 1;
        else
            mapaReps[col.front()] = 0;
        tmp.push(col.front());
        col.pop();
        i += 1;
    }
    while (!col.empty()) {
        col.push(tmp.front());
        tmp.pop();
        i -= 1;
    }
    return ans;
}

/* Esta operación tiene complejidad O(n*log(n)) donde n es el tamaño de la cola, pues recorre toda la cola y
 * hace la operación find que tiene complejidad en el peor de los casos O(log n)
*/

// Punto 9

bool verificarRepetidos2(queue<Elemento>& col){
    int i = 0;
    bool ans = false;
    queue<Elemento> tmp;
    map<Elemento, int> mapaReps;
    map<Elemento, int>::iterator it;
    while (!col.empty() && !ans){
        it = mapaReps.find(col.front());
        if (it != mapaReps.end())
            ans = true;
        else
            mapaReps[col.front()] = 0;
        tmp.push(col.front());
        col.pop();
        i += 1;
    }
    while (!col.empty()){
        col.push(tmp.front());
        tmp.pop();
        i -= 1;
    }
    return ans;
}

/* Esta operación en el peor caso tiene complejidad O(n * log n) porque hace el find n veces y este tiene complejidad
 *O(log n) y se da cuando ningún elemento de la cola está repetido y en el mejor de los casos la complejidad es O(1)
 * puesto que la operación find se ejecutaría con un mapa de un solo valor entonces su complejidad es constante y lo demás
 * se ejecutaría en tiempos constante. Este caso se da cuando el segundo elemento es igual al primero.
*/

int obtenerMenorCosto(list<int>& l) {
    priority_queue<int, vector<int>, greater<int>> p;
    int ans = 0;
    int suma = 0;
    int i = 0;
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); it++){
        p.push((*it));
        i += 1;
    }
    ans += p.top();
    p.pop();
    ans += p.top();
    p.pop();
    suma = ans;
    i -= 2;
    while (i > 0){
        suma += p.top();
        ans += suma;
        p.pop();
        i -= 1;
    }
    return ans;
}
/* Esta operación tiene complejidad O(n * log n) donde n es el tamaño de la lista, porque la cola de prioridad que
 * se implementa es un montículo y al organizarlo esto da como complejidad (log n) cada vez que se inserta un 
 * elemento y esto se ejecuta n veces, ya luego es simplemente sumar lo elementos ya ordenados
 */
// Punto 3
/*
bool verificarOrdenadoCola(queue<int> &c){
	int elem1 = c.front();
	bool ans = true;
	list<int> tmp;
	tmp.push_back(elem1);
	c.pop();
	int elem2 = c.front();
	tmp.push_back(elem2);
	c.pop();
	if(elem1 < elem2){
		while(ans && !c.empty){

		}
	}
}
*/
int main() {
    list<int> l;
    stack<int> pil;
    l.push_back(1);
    l.push_back(3);
    pil.push(1);
    pil.push(2);
    pil.push(3);
    pil.push(4);
    
    eliminarPosicionesPila(pil, l);
    while (!pil.empty()){
        cout << pil.top() << " ";
        pil.pop();
    }
    cout << endl;
    l.push_back(5);
    l.push_back(2);
    int menorCosto = obtenerMenorCosto(l);
    cout << "Menor costo: " << menorCosto << endl;
    return 0;
}
