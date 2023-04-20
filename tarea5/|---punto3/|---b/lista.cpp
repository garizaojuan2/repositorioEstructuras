#include "lista.h"

Lista::Lista(){
  act = NULL;
}


void Lista::insListaOrdenada(Elemento elem)
{
  Nodo* tmp, *ant;// se ejecuta una vez
  Nodo* nuevo = new Nodo;// se ejecuta una vez
  nuevo->dato = elem;// se ejecuta una vez
  nuevo->sig = NULL;// se ejecuta una vez

  if(act == NULL)//en el peor caso se ejecuta 0 veces y en el mejor 1 vez
    act = nuevo;//en el peor caso se ejecuta 0 veces y en el mejor 1 vez
  else
  {
    tmp = act;//en el peor caso se ejecuta 1 vez y en el mejor 0
    ant = NULL;//en el peor caso se ejecuta 1 vez y en el mejor 0
    if(elem <= tmp->dato)//en el peor caso se ejecuta 0 veces y en el mejor 1 vez
    {
      nuevo->sig = tmp;//en el peor caso se ejecuta 0 veces y en el mejor 1 vez
      act = nuevo;//en el peor caso se ejecuta 0 veces y en el mejor 1 vez
    }
    else
    {
      while(tmp != NULL && elem <= tmp->dato)// en el peor caso se ejecuta n + 1 veces donde n es el tamaño de la lista o 
                                             //la posición en la que encuentra un elemento menor al que se quiere agregar
      {
        ant = tmp;// en el peor caso se ejecuta n veces donde n es el tamaño de la lista o 
                  //la posición en la que encuentra un elemento menor al que se quiere agregar
        tmp = tmp->sig;// en el peor caso se ejecuta n veces donde n es el tamaño de la lista
                      //la posición en la que encuentra un elemento menor al que se quiere agregar
      }
      nuevo->sig = tmp;// en el peor caso se ejecuta 1 vez y en el mejor 0.
      ant->sig = nuevo;// en el peor caso se ejecuta 1 vez y en el mejor 0.
    }

// en los mejores casos, se ejecuta en complejidad O(1) y en el peor caso O(n^2)
  }
}


void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}
