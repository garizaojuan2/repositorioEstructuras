/*

Ejemplo de uso TAD lista implementación estructuras enlazadas simples.

*/

#include "lista.h"
#include <iostream>

int main(){
  Lista l, l2, l3;
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

  l3 = l + l2;
  cout << "Valor posicion 1: " << l3.infoLista(1) << endl;
  cout << "Valor posicion 2: " << l3.infoLista(2) << endl;
  cout << "Valor posicion 3: " << l3.infoLista(3) << endl;
  cout << "Valor posicion 4: " << l3.infoLista(4) << endl;
  cout << "Valor posicion 5: " << l3.infoLista(5) << endl;
  cout << "Valor posicion 6: " << l3.infoLista(6) << endl;
  cout << "Valor posicion 7: " << l3.infoLista(7) << endl;
  cout << "Valor posicion 8: " << l3.infoLista(8) << endl;


  return 0;
}
