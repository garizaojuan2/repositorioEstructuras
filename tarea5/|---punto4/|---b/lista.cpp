#include "lista.h"

Lista::Lista(){
  act = NULL;
}

void Lista::anxLista(Elemento elem){
  Nodo* tmp;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(act == NULL)
    act = nuevo;
  else{
    tmp = act;
    while(tmp->sig != NULL)
      tmp = tmp->sig;
    tmp->sig = nuevo;
  }
}

void Lista::insLista(Elemento elem, int pos){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      nuevo->sig = act;
      act = nuevo;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++)
	tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      tmp->sig = nuevo;
    }
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

Lista Lista::operator +(Lista &l)
{
  Lista ans;// se ejecuta una vez
  Nodo* tmp = act;// se ejecuta una vez
  int tam = l.longLista(), i;// se ejecuta dos veces
  Elemento elem;// se ejecuta una vez
  while(tmp != NULL)// se ejecuta n + 1 veces donde n es el tamaño de la lista1
  {
    elem = tmp->dato;// se ejecuta n veces donde n es el tamaño de la lista1
    ans.anxLista(elem);// se ejecuta n veces donde n es el tamaño de la lista1
    tmp = tmp->sig;// se ejecuta n veces donde n es el tamaño de la lista1
  }
  for(i = 1; i <= tam; i++)// se ejecuta n + 1 veces donde n es el tamaño de la lista2
  {
    elem = l.infoLista(i);// se ejecuta n veces donde n es el tamaño de la lista2
    ans.anxLista(elem);// se ejecuta n veces donde n es el tamaño de la lista2
  } 

  return ans;// se ejecuta una vez
// esta operación tiene complejidad de O(n^2)
}
