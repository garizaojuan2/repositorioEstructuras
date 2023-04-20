/*

Ejemplo de uso TAD lista implementación estructuras enlazadas simples.

*/

#include "lista.h"
#include <iostream>

void concatenarListas(Lista l1, Lista l2)
{
  int i;// se ejecuta 1 vez
  int tam = l2.longLista();// se ejecuta n veces donde n es el tamaño de la lista
  for(i = 1; i <= tam; i++)// se ejecuta n + 1 veces donde n es el tamaño de la lista
  {
    Elemento num = l2.infoLista(i);// se ejecuta n veces
    l1.anxLista(num);// se ejecuta n veces
  }
// esta operación tiene complejidad de O(n^2)
}

int main(){
  Lista l, l2;
  l.anxLista(5);
  l.anxLista(10);
  l.anxLista(12);
  l.anxLista(15);

  cout << "Valor posicion 1: " << l.infoLista(1) << endl;
  cout << "Valor posicion 2: " << l.infoLista(2) << endl;
  cout << "Valor posicion 3: " << l.infoLista(3) << endl;
  cout << "Tamano: " << l.longLista() << endl;

  l2.anxLista(5);
  l2.anxLista(10);
  l2.anxLista(12);
  l2.anxLista(15);
  concatenarListas(l,l2);
  cout << "Valor posicion 1: " << l.infoLista(1) << endl;
  cout << "Valor posicion 2: " << l.infoLista(2) << endl;
  cout << "Valor posicion 3: " << l.infoLista(3) << endl;
  cout << "Valor posicion 4: " << l.infoLista(4) << endl;
  cout << "Valor posicion 5: " << l.infoLista(5) << endl;
  cout << "Valor posicion 6: " << l.infoLista(6) << endl;
  cout << "Valor posicion 7: " << l.infoLista(7) << endl;
  cout << "Valor posicion 8: " << l.infoLista(8) << endl;


  return 0;
}
