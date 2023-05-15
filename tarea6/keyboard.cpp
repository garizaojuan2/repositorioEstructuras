#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
	string line, cad;
	int i, sumar;
	list<char>::iterator it, tmp;
	while(cin >> line){
		list<char> ans;
		bool flag1 = false;
		list<char>::iterator it;
		i = 0; 
		while(i < line.size()){// se ejecuta n + 1 veces donde n es el tamaño de la linea
			if(line[i] == '['){// en el peor caso, se ejecuta una vez y en el mejor ninguna
				sumar = 0;// en el peor caso, se ejecuta una vez y en el mejor ninguna
				flag1 = true;// en el peor caso, se ejecuta una vez y en el mejor ninguna
			}
			else if(line[i] != '[' && line[i] != ']' && flag1){// en el peor caso se ejecuta n - 1 veces y en el mejor ninguna
				it = ans.begin();// en el peor caso se ejecuta n - 1 veces y en el mejor ninguna
				for(int j = 0; j < sumar; j++)// en el peor caso se ejecuta n(n - 1)  veces y en el mejor ninguna
					it++;// en el peor caso se ejecuta n - 1(n - 1)  veces y en el mejor ninguna
				sumar += 1;// en el peor caso se ejecuta n - 2 veces y en el mejor ninguna
				ans.insert(it, line[i]);// en el peor caso se ejecuta n - 2 veces y en el mejor ninguna
			}
			else if(line[i] == ']')// en el mejor caso, no se ejecuta ninguna vez y en el peor tampoco
				flag1 = false;// en el mejor caso, no se ejecuta ninguna vez y en el peor tampoco
			else{
				ans.push_back(line[i]);// en el mejor caso se ejecuta n veces
			}
			i += 1;	// se ejecuta n veces
		}
		for(it = ans.begin(); it != ans.end(); it++){
			cout << (*it);
		}
		cout << endl;
	}
	return 0;
}

/* Se puede denotar que en el peor caso, que se da cuando el primer elemento de la linea es igual a [  y el resto solo son
 * carácteres diferentes a ] o a [ y el mejor caso se da cuando todos los elementos de la linea son diferentes a [ y a ] y solo se agregan
 * los carácteres, de forma regular
 * En el peor caso, la complejidad es O(n^2) y en el mejor caso es O(n)
*/
