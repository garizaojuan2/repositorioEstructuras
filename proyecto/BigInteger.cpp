/*
* Autor: Juan Sebastián Garizao Puerto 
* Fecha: 01 de mayo de 2023
* Implementación TAD Big Integer
*/

#include "BigInteger.h"

BigInteger::BigInteger(Number)
{
	int tam = Number.size();
	int digit;
	int i = 0;
	if(Number[0] == '-')
	{
		digit = (Number[1] - '0') * -1;
		vecDigits.push_back(digit);
		size += 1;
		i += 2;
	}
	while(i < tam)
	{
		digit = Number[i] - '0';
		vecDigits.push_back(digit);
		size += 1;
		i += 1;
	}
}

BigInteger::BigInteger(BigInteger &b){
	size = b.getSize();
	for(int i = 0; i < size; i++){
		vecDigits[i] = getDigit(i);
	}
}

int BigInteger::getDigit(int pos){
	return vecDigits[pos];
}

int BigInteger::getSize(){
	return vecDigits.size();
}

bool BigInteger::operator ==(BigInteger &num){
	bool ans = true;
	if(vecDigits.size() != num.getSize()){
		ans = false;
	}
	else{
		int i = 0;
		while(i < vecDigits.size()  && ans){
			if(vecDigits[i] != num.getDigit(i))
				ans = false;
			i += 1;
		}
	}
	return ans;
}

bool BigInteger::operator <(BigInteger &num){
	bool ans = false;
	if(vecDigits.size()  != num.getSize() && (vecDigits[0] > 0 && num.getDigit(0) > 0)){
		ans = vecDigits.size() < num.getSize();
	}
	else if(vecDigits.size() != num.getSize() && (vecDigits[0] < 0 && num.getDigit(0) < 0))
	{
		ans = vecDigits.size() > num.getSize();
	}
	else if(vecDigits.size() != num.getSize() && ((vecDigits[0] < 0 && num.getDigit(0) > 0) || (vecDigits[0] > 0 && num.getDigit(0) < 0))){
		ans = vecDigits[0] < num.getDigit(0);
	}
	else{
		int i = 0;
		while(i < vecDigits.size()){
			if(vecDigits[i] != num.getDigit(i)){
				ans = vecDigits[i] < num.getDigit();
				i = vecDigits.size();
			}
			i += 1;
		}

	}
	return ans;
}

bool BigInteger::operator <=(BigInteger &num){
	bool ans = true;
	if(vecDigits.size()  != num.getSize() && (vecDigits[0] > 0 && num.getDigit(0) > 0)){
		ans = vecDigits.size() < num.getSize();
	}
	else if(vecDigits.size() != num.getSize() && (vecDigits[0] < 0 && num.getDigit(0) < 0))
	{
		ans = vecDigits.size() > num.getSize();
	}
	else if(vecDigits.size() != num.getSize() && ((vecDigits[0] < 0 && num.getDigit(0) > 0) || (vecDigits[0] > 0 && num.getDigit(0) < 0))){
		ans = vecDigits[0] < num.getDigit(0);
	}
	else{
		int i = 0;
		while(i < vecDigits.size()){
			if(vecDigits[i] != num.getDigit(i)){
				ans = vecDigits[i] < num.getDigit();
				i = vecDigits.size();
			}
			i += 1;
		}

	}
	return ans;
}

string BigInteger::toString(){
	string ans;
	for(int i; i < vecDigits.size();i++){
		char digit = '0' + vecDigits[i];
		ans += digit;
	}
	return ans;
}

// Esta operacion apenas está empezando a ser planteada
void BigInteger::add(BigInteger &num){
	if(vecDigits[0] > 0 && num.getDigit(0) > 0){
		int tam1 = vecDigits.size(), tam2 = num.getSize(), sum, carry;
		int tam = (tam1 < tam2) ? tam1: tam2;
		for(int i = 1; i <= tam; i++){
			sum = vecDigits[tam1 - i] + num.getDigit(tam2 - i) % 10;
			if(carry > 0)
				sum += carry;
			carry = vecDigits[tam1 - i] + num.getDigit(tam2 - i) / 10;
			vecDigits[tam1 - i] += sum;
		}
	}
}


