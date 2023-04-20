#include "lista.h"
#include <iostream>

int contarOcurrencias(Lista l, int v)
{
	int tam = l.longLista(); // esta línea se ejecuta n veces, donde n es el tamaño de la lista
	int i, ans = 0, pos; // se ejecuta 3 veces
	for(i = 1; i <= tam; i++) // se ejecuta n + 1 veces
	{
		pos = l.infoLista(i); // se ejecuta n veces 
		if(pos == v) // en el peor caso se ejecuta n veces y en el mejor 0 veces
		{
			ans += 1; // en el peor caso se ejecuta n veces y en el mejor 0 veces
		}
	}
	return ans; // se ejecuta 1 vez
}
// La complejidad de esta función es O(n^2), tanto en peor como en peor caso, pues implícitamente hay dos ciclos anidados que depende
// uno del otro.
Lista obtenerMenores(Lista l, int v)
{
	int tam = l.longLista();// esta línea se ejecuta n veces, donde n es el tamaño de la lista
	int i, pos;// se ejecuta 2 veces
	Lista ans;// se ejecuta 1 vez
	for(i = 1; i <= tam; i++) // se ejecuta n + 1 veces 
	{
		pos = l.infoLista(i); // se ejecuta n veces 
		if(pos < v) // en el peor caso se ejecuta n veces y en el mejor 0 veces
		{
			ans.anxLista(pos); // en el peor caso se ejecuta n veces y en el mejor 0 veces
		}
	}
	return ans; // se ejecuta 1 vez
}

int main()
{
	Lista l;
  	l.anxLista(5);
  	l.anxLista(5);
  	l.anxLista(5);
  	l.anxLista(5);
  	cout << "Tamano: " << l.longLista() << endl;
  	int x = contarOcurrencias(l, 5);
  	Lista result = obtenerMenores(l, 6);
  	cout << x << endl;
  	for(int i = 1; i < result.longLista(); i++)
  	{
  		cout << result.infoLista(i) << endl;
  	}

	return 0;
}
