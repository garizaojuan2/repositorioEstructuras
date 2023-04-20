
#include "lista.h"
#include <iostream>

void insertarEnListaOrdenada(Lista l, Elemento v)
{
  int tam = l.longLista(); // se ejecuta n veces, donde n es el tamaño de la lista
  int i = 1;// se ejecuta una vez
  bool flag = true;// se ejecuta una vez

  if(tam == 0)
  {
    l.anxLista(v);
  }
  else
  {
    while(i + 1 <= tam && flag)// en el peor de los casos se ejecuta n veces y en el mejor solo una vez
    {
      Elemento sig = l.infoLista(i + 1)// en el peor caso se ejecuta n - 1 veces y en el mejor caso solo una vez
      if(v <= sig)// en el peor caso nunca se ejecuta y en el mejor caso se ejecuta una sola vez
      {
        l.insLista(v, i + 1);// en el peor caso nunca se ejecuta y en el mejor caso se ejecuta una sola vez
        flag = false;// en el peor caso nunca se ejecuta y en el mejor caso se ejecuta una sola vez
      }
      i += 1;// en el peor caso se ejecuta n - 1 veces y en el mejor caso solo una vez
    }
  }
}




int main(){
  Lista l;
  l.anxLista(5);
  l.anxLista(10);
  l.anxLista(12);
  l.anxLista(15);

  cout << "Valor posicion 1: " << l.infoLista(1) << endl;
  cout << "Valor posicion 2: " << l.infoLista(2) << endl;
  cout << "Valor posicion 3: " << l.infoLista(3) << endl;
  cout << "Tamano: " << l.longLista() << endl;

  insertarEnListaOrdenada(l, 13);
  cout << "Valor posicion 1: " << l.infoLista(1) << endl;
  cout << "Valor posicion 2: " << l.infoLista(2) << endl;
  cout << "Valor posicion 3: " << l.infoLista(3) << endl;
  cout << "Valor posicion 4: " << l.infoLista(4) << endl;
  cout << "Tamano: " << l.longLista() << endl;

  return 0;
}
