#include <string>
#include <list>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    bool flag;
    int i, cont, tam;
    string word;
    cin >> word;
    cin.ignore();
    list<string> dicWord;
    while (word != "#"){
        dicWord.push_back(word);
        cin >> word;
        cin.ignore();
    }
    int pos;
    string line;
    getline(cin, line);
    while (line[0] != '#'){
        i = 0;
        vector<int> cant(26, 0), replica;
        while (i < line.size()){
            if (line[i] != ' '){
                pos = line[i] - 'a';
                cant[pos] += 1;
            }
            i++;
        }
        replica = cant;
        list<string>::iterator it;
        cont = 0;
        for (it = dicWord.begin(); it != dicWord.end(); it++){ // se ejecuta n + 1 veces donde n es el tamaño del diccionario
            tam = (*it).size(); // se ejecuta n veces
            i = 0; // se ejecuta n veces
            flag = true; // se ejecuta n veces
            while (i < tam && flag){//  en el peor caso, se ejecuta n*(m + 1) veces, pensando que el tamaño de la palabra es igual a m, y en el mejor n veces
                pos = (*it)[i] - 'a';// se ejecuta n*m veces en el peor caso y n en el mejor caso
                if (cant[pos] <= 0) // no se ejecuta en el peor caso y se ejecuta n veces en el mejor caso
                    flag = false;// no se ejecuta en el peor caso y se ejecuta n veces en el mejor caso
                else
                    cant[pos] -= 1; // se ejecuta n*m veces en el peor caso y 0 veces en el mejor caso
                i++; // se ejecuta n veces en el mejor caso y n*(m + 1) veces en el peor caso
            }
            cant = replica; // se ejecuta n veces
            if(flag) // en el peor caso se ejecuta n veces y en el mejor nunca se ejecuta
                cont += 1; // en el peor caso se ejecuta n veces y en el mejor nunca se ejecuta
        }
        cout << cont << endl;
        getline(cin, line);
    }
    return 0;
}


// El peor caso se da cuando las letras forman todas las palabras del diccionario
// El mejor caso se da cuando la primera letra de las palabras tienen en el primer elemento una letra que está con un valor de 0 en cant

// En el mejor caso la complejidad es lineal O(n) y el peor caso tiene una complejidad cuadrática O(n*m) dejando la salvedad que si bien son
// dos variables independientes, terminan haciendo dos ciclos anidados.