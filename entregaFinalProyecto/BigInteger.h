/*
* Autor: Juan Sebastián Garizao Puerto 
* Fecha: 01 de mayo de 2023
* Implementación TAD Big Integer
*/
#include <vector>
#include <string>
#include <iostream>
#include <list>
#ifndef BIGINTEGER_H
#define BIGINTEGER_H

using namespace std;


class BigInteger
{
private:
	vector<int> vecDigits;
	void sumIguales(BigInteger& num1, BigInteger& num2);
	void sumDiff(BigInteger& num1, BigInteger& num2);
	void quitarCeros();
	void cambiarSigno();
	void addDigit(int digit);
	pair<string, string> divMod(BigInteger& num);

public:
	// Creación de prototipos de las funciones del TAD Big Integer
	BigInteger(string& number); 
	BigInteger(const BigInteger& num);
	int getDigit(int pos); 
	int getSize();
	void add(BigInteger& num); 
	void product(BigInteger& num);
	void substract(BigInteger& num); 
	void quotient(BigInteger& num); 
	void remainder(BigInteger& num); 
	void pow(int potencia);
	string toString();
	BigInteger operator +(BigInteger& num);
	BigInteger operator -(BigInteger& num); 
	BigInteger operator *(BigInteger& num); 
	BigInteger operator /(BigInteger& num); 
	BigInteger operator %(BigInteger& num); 
	bool operator ==(BigInteger& num);
	bool operator <(BigInteger& num);
	bool operator <=(BigInteger& num);
	static BigInteger sumarListaValores(list<BigInteger>& b);
	static BigInteger multiplicarListaValores(list<BigInteger>& b);
	

};


#endif