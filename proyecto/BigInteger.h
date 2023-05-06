/*
* Autor: Juan Sebastián Garizao Puerto 
* Fecha: 01 de mayo de 2023
* Implementación TAD Big Integer
*/
#include <vector>
#include <string>
#include <iostream>

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

using namespace std;
typedef string Number;

class BigInteger
{
private:
	vector<int> vecDigits;
public:
	// Creación de prototipos de las funciones del TAD Big Integer
	BigInteger(&Number); // constructora que recibe un número como cadena y guarda los digitos como numeros en vecDigits
	BigInteger(BigInteger &b); // constructora que recibe un BigInteger
	int getDigit(int pos); // obtiene el valor de un dígito en una posición dada
	int getSize(); // obtiene el numero de digitos del BigInteger
	void add(BigInteger &num); // le suma un bigInteger a otro y cambia el valor del número que se pasa
	void product(BigInteger &num);// le multiplica un bigInteger a otro y cambia el valor del número que se pasa
	void substract(BigInteger &num); // le resta un bigInteger a otro y cambia el valor del número que se pasa
	void quotient(BigInteger &num); // le divide un bigInteger a otro y cambia el valor del número que se pasa
	void remainder(BigInteger &num); // obtiene el residuo entre dos bigInteger y cambia el valor del numero que se pasa
	void pow(int potencia);// eleva un big Integer a una potencia dada
	string toString();// convierte a string los valores de un BigInteger dado
	BigInteger operator +(BigInteger &num); // sobrecarga que le suma un bigInteger a otro y lo guarda en otra variable
	BigInteger operator -(BigInteger &num); // sobrecarga que le resta un bigInteger a otro y lo guarda en otra variable 
	BigInteger operator *(BigInteger &num); // sobrecarga que le multiplica un bigInteger a otro y lo guarda en otra variable
	BigInteger operator /(BigInteger &num); // sobrecarga que le divide un bigInteger a otro y lo guarda en otra variable
	BigInteger operator %(BigInteger &num); // sobrecarga que obtiene el residuo entre dos bigInteger y lo guarda en otra variable
	bool operator ==(BigInteger &num);//sobrecarga que identifica si dos BigInteger son iguales
	bool operator <(BigInteger &num);//sobrecarga que identifica si un BigInteger es estrictamente menor que otro
	bool operator <=(BigInteger &num);//sobrecarga que identifica si un BigInteger es menor o igual que otro
	

};


#endif