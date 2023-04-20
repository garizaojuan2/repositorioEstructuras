
#include "lista.h"
#include <iostream>

int main(){
  cout << "entre" << endl;
  Lista l;
  l.insListaOrdenada(20);
  cout << "primera" << endl;
  l.insListaOrdenada(10);
  l.insListaOrdenada(8);
  l.insListaOrdenada(0);

  cout << "Valor posicion 1: " << l.infoLista(0) << endl;
  cout << "Valor posicion 2: " << l.infoLista(2) << endl;
  cout << "Valor posicion 3: " << l.infoLista(3) << endl;
  cout << "Tamano: " << l.longLista() << endl;

  

  return 0;
}
