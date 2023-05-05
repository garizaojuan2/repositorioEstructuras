/*
 * Autores: Juan Sebastián Garizao Puerto y Kevin Peréz
 * Fecha: 05 de mayo de 2023
 * Implementación TAD Colas de Prioridad
*/

#include "ColasDePrioridad.h"

int main(){
    ColasDePrioridad c1;
    bool vacio = c1.empty();
    if(vacio)
        cout << "La cola de prioridad esta vacia" << endl;
    else
        cout << "La cola de prioridad  no esta vacia" << endl;
    c1.enqueue(2);
    c1.enqueue(7);
    c1.enqueue(1);
    c1.enqueue(0);
    c1.enqueue(12);

    int num = c1.front();
    cout << num << endl;
    c1.deque();
    cout << "Eliminando el numero " << num << endl;
    num = c1.front();
    cout << num << endl;
    c1.deque();
    cout << "Eliminando el numero " << num << endl;
    vacio = c1.empty();
    if(vacio)
        cout << "La cola de prioridad esta vacia" << endl;
    else
        cout << "La cola de prioridad  no esta vacia" << endl;


    return 0;
}

