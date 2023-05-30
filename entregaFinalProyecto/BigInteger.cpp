/*
* Autor: Juan Sebastián Garizao Puerto 
* Fecha: 01 de mayo de 2023
* Implementación TAD Big Integer
*/

#include "BigInteger.h"


/*
Constructora 1

Entrada: Una cadena que contiene un entero
Salida: Un BigInteger

Descripción: Se rellena un vector que contiene los dígitos dados por una cadena. Se ordenan del dígito con menor
valor número hasta el mayor. El último elemento del vector, es el signo que tiene el número.

*/
BigInteger::BigInteger(string& number)
{
	int tam = number.size();
	int digit, signo = 1;
	int i = tam - 1;
	int fin = 0;
	if(number[0] == '-')
	{
		signo = -1;
		fin = 1; 
	}

	while(i >= fin){
		digit = number[i] - '0';
		vecDigits.push_back(digit);
		i -= 1;
	}
	vecDigits.push_back(signo);
}
/*
Constructora 2

Entrada: Un BigInteger
Salida: Un BigInteger

Descripción: Se copia un BigInteger pasado por parárametro a otro, copiando todos los dígitos en el 
vector del nuevo BigInteger 
*/
BigInteger::BigInteger(const BigInteger& num){
	vecDigits = vector<int>(num.vecDigits);
}

/*
Función getDigit

Entrada: Un BigInteger y un entero positivo
Salida: Un entero positivo

Descripción: Retorna el dígito que esté en una posición de un BigInteger pasado como parámetro, partiendo de la posición que
se pasa
*/
int BigInteger::getDigit(int pos){
	return vecDigits[pos];
}

/*
Función getSize

Entrada: Un BigInteger
Salida: Un entero positivo

Descripción: Retorna la cantidad de dígitos + 1, donde ese número de más, es el signo del número, de un BigInteger pasado
como parámetro
*/

int BigInteger::getSize(){
	return vecDigits.size();
}

/*
Sobrecarga ==

Entrada: Dos BigInteger
Salida: Un booleano

Descripción: Retorna verdadero si dos BigInteger pasados como parámetro son iguales en todos sus aspectos.
En caso contrario, retorna falso.
*/

bool BigInteger::operator ==(BigInteger& num){
	bool ans = true;
	if(vecDigits.size() != num.getSize() || (num.getDigit(num.getSize() - 1) != vecDigits[vecDigits.size() - 1])){
		ans = false;
	}
	else{
		int i = 0;
		while(i < vecDigits.size() - 1  && ans){
			if(vecDigits[i] != num.getDigit(i))
				ans = false;
			i += 1;
		}
	}
	return ans;
}

/*
Sobrecarga <

Entrada: Dos BigInteger
Salida: Un booleano

Descripción: Retorna verdadero si el primer BigInteger pasado como parámetro es menor que el segundo BigInteger pasado como 
parámetro en todos sus aspectos. En caso contrario, retorna falso.
*/

bool BigInteger::operator <(BigInteger& num){
	bool ans = false;
	if(vecDigits.size()  != num.getSize()){
		if(vecDigits[vecDigits.size() - 1] > 0 && (num.getDigit(num.getSize() - 1) > 0))
			ans = vecDigits.size() < num.getSize();
		else if((vecDigits[vecDigits.size() - 1] < 0 && (num.getDigit(num.getSize() - 1) < 0)))
			ans = vecDigits.size() > num.getSize();
		else if(((vecDigits[vecDigits.size() - 1] < 0 && (num.getDigit(num.getSize() - 1) > 0)) || (vecDigits[vecDigits.size() - 1] > 0 && (num.getDigit(num.getSize() - 1) < 0))))
			ans = vecDigits[vecDigits.size() - 1] < num.getDigit(num.getSize() - 1);
	}
	else{
		int i = vecDigits.size() - 2;
		while(i >= 0){
			if(vecDigits[i] != num.getDigit(i)){
				ans = vecDigits[i] < num.getDigit(i);
				i = 0;
			}
			i -= 1;
		}

	}
	return ans;
}

/*
Sobrecarga <=

Entrada: Dos BigInteger
Salida: Un booleano

Descripción: Retorna verdadero si el primer BigInteger pasado como parámetro es menor o igual que el segundo BigInteger pasado 
como parámetro en todos sus aspectos. En caso contrario, retorna falso.
*/


bool BigInteger::operator <=(BigInteger& num){
	bool ans = true;
	if(vecDigits.size()  != num.getSize()){
		if(vecDigits[vecDigits.size() - 1] > 0 && (num.getDigit(num.getSize() - 1) > 0))
			ans = vecDigits.size() < num.getSize();
		else if((vecDigits[vecDigits.size() - 1] < 0 && (num.getDigit(num.getSize() - 1) < 0)))
			ans = vecDigits.size() > num.getSize();
		else if(((vecDigits[vecDigits.size() - 1] < 0 && (num.getDigit(num.getSize() - 1) > 0)) || (vecDigits[vecDigits.size() - 1] > 0 && (num.getDigit(num.getSize() - 1) < 0))))
			ans = vecDigits[vecDigits.size() - 1] < num.getDigit(num.getSize() - 1);
	}
	else{
		int i = vecDigits.size() - 2;
		while(i >= 0){
			if(vecDigits[i] != num.getDigit(i)){
				ans = vecDigits[i] < num.getDigit(i);
				i = 0;
			}
			i -= 1;
		}
	}
	return ans;
}
/*
Función toString

Entrada: un BigInteger
Salida: Un string

Descripción: Retorna un string que representa un BigInteger pasado como parámetro, con su respectivo signo.
*/
string BigInteger::toString(){
	string ans;
	int tam = vecDigits.size();
	if(vecDigits[tam - 1] == -1)
		ans += '-';
	for(int i = tam - 2; i >= 0;i--){
		char digit = '0' + vecDigits[i];
		ans += digit;
	}
	return ans;
}

/*
Operación auxiliar sumIguales

Entrada: dos BigInteger
Salida: la suma de esos dos BigInteger

Descripción: realiza una suma donde se asume que el primer BigInteger dado como parámetro, es más grande que el segundo 
BigInteger dado como parámetro y se sabe que los dos enteros dados, tienen el mismo signo.
*/
void BigInteger::sumIguales(BigInteger& num1, BigInteger &num2){
	int tam1 = num1.getSize();
	int tam2 = num2.getSize();
	int signo = vecDigits[vecDigits.size() - 1]; 
	int carry = 0, sum, i;
	char digit;
	for(i = 0; i < tam2 - 1; i++){
		sum = (num1.getDigit(i) + num2.getDigit(i) + carry) % 10;
		carry = (num1.getDigit(i) + num2.getDigit(i) + carry) / 10;
		vecDigits[i] = sum;
	}
	if(vecDigits.size() == i){
		vecDigits.pop_back();
		while(i < tam1 - 1){
			sum = (num1.getDigit(i) + carry) % 10;
			carry = (num1.getDigit(i) + carry) / 10;
			vecDigits.push_back(sum);
			i += 1;
		}
		if(carry != 0){
			vecDigits.push_back(carry);
		}
		vecDigits.push_back(signo);
	}
	else{
		while(i < tam1 - 1 && carry > 0){
			sum = (num1.getDigit(i) + carry) % 10;
			carry = (num1.getDigit(i) + carry) / 10;
			vecDigits[i] = sum;
		}
		if(carry != 0){
			vecDigits.pop_back();
			vecDigits.push_back(carry);
			vecDigits.push_back(signo);
		}
	}
}
/*
Operación auxiliar sumDiff

Entrada: dos BigInteger
Salida: la resta de esos dos BigInteger

Descripción: realiza una resta donde se asume que el primer BigInteger dado como parámetro, es más grande que el segundo 
BigInteger dado como parámetro y se sabe que los dos enteros dados, tienen diferente signo.
*/

void BigInteger::sumDiff(BigInteger& num1,BigInteger& num2){
	int tam1 = num1.getSize();
	int tam2 = num2.getSize();
	int signo = num1.getDigit(tam1 - 1);
	int carry = 0, resta, i;
	for(i = 0; i < tam2 - 1; i++){
		resta = num1.getDigit(i) + carry;
		if(resta == -1)
			resta = 9;
		else
			carry = 0;
		if(resta < num2.getDigit(i)){
			carry = -1;
			resta += 10;
		}
		resta -= num2.getDigit(i);
		vecDigits[i] = resta;
	}
	if(vecDigits.size() == i){
		vecDigits.pop_back();
		while(i < tam1 - 1){
			resta = num1.getDigit(i) + carry;
			if(resta == -1)
				resta += 10;
			else
				carry = 0;
			vecDigits.push_back(resta);
			i += 1;
		}
		vecDigits.push_back(signo);
	}
	else{
		while(carry == -1 && i < tam1 - 1){
			resta = vecDigits[i] + carry;
			if(resta == -1)
				resta += 10;
			else
				carry = 0;
			vecDigits[i] = resta;
		}
	}
}

/*
Operación auxiliar quitarCeros

Entrada: un BigInteger
Salida: un BigInteger sin ceros a la izquierda

Descripción: realiza un recorrido sobre el BigInteger pasado como parámetro, quitando todos los ceros que haya, hasta 
que encuentre un número con valor mayor que 0.
*/


void BigInteger::quitarCeros(){
	int tam = vecDigits.size();
	int signo = vecDigits[tam - 1];
	vecDigits.pop_back();
	while(tam - 1 > 0){
		if(vecDigits[tam - 1] == 0)
			vecDigits.pop_back();
		else
			tam = 0;
		tam -= 1;
	}
	vecDigits.push_back(signo);
}

/*
Operación add

Entrada: dos BigInteger
Salida: la suma de esos dos BigInteger

Descripción: realiza una suma entre dos BigInteger pasados como parámetro. Esta operación, a partir de ciertas condiciones,
indica cómo usar una operación auxiliar u otra. Guarda el resultado en el primer BigInteger pasado como parámetro.
*/
void BigInteger::add(BigInteger& num){
	int tam1 = vecDigits.size();
	int tam2 = num.getSize();
	if(vecDigits[tam1 - 1] > 0 && num.getDigit(tam2 - 1) > 0){
		if((*this) < num)
			this->sumIguales(num, (*this));
		else
			this->sumIguales((*this), num);
	}
	else if(vecDigits[tam1 - 1] < 0 && num.getDigit(tam2 - 1) < 0){
		if((*this) < num)
			this->sumIguales((*this), num);
		else
			this->sumIguales(num, (*this));
	}	
	else{
		vecDigits[tam1 - 1] *= -1;
		if((*this) < num){
			vecDigits[tam1 - 1] *= -1;
			this->sumDiff(num, (*this));
		}
		else{
			vecDigits[tam1 - 1] *= -1;
			this->sumDiff((*this),num);
		}
		this->quitarCeros();
	}
}

/*
Operación auxiliar cambiar signo.

Entrada: un BigInteger.
Salida: el mismo BigInteger, pero con el signo cambiado.

Descripción: realiza un cambio de signo sobre un BigInteger pasado como parámetro.
*/
void BigInteger::cambiarSigno(){
	int tam = vecDigits.size();
	vecDigits[tam - 1] *= -1;
}

/*
Operación substract

Entrada: dos BigInteger
Salida: la resta de esos dos BigInteger

Descripción: realiza una resta entre dos BigInteger, utilizando la operación add. Le cambio el signo al segundo BigInteger
pasado como parámetro, realiza sobre el primer BigInteger pasado como parámetro la operación add, 
con el cambio hecho al segundo BigInteger.
*/
void BigInteger::substract(BigInteger& num){
	int tam1 = vecDigits.size();
	int tam2 = num.getSize();
	num.cambiarSigno();
	this->add(num);
	num.cambiarSigno();
}

/*
Operación product

Entrada: dos BigInteger
Salida: el producto de esos dos BigInteger

Descripción: realiza una multiplicación, donde se crea un número solo, que a partir de la multiplicación de los dígitos del
segundo BigInteger pasado como parámetro con el primero, se le va sumando dígito a dígito y al final se copia lo de ese vector
en el vector original.
*/

void BigInteger::product(BigInteger& num){
	int tam1 = vecDigits.size(), multi = num.getDigit(0);
	int tam2 = num.getSize();
	int ini = 1, sum = 0, carry = 0, carry2 = 0;
	int signo = vecDigits[tam1 - 1] * num.getDigit(tam2 - 1);
	vector<int> result;
	for(int i = 0; i < tam1 - 1; i++){
		sum = ((vecDigits[i] * multi) + carry) % 10;
		carry = ((vecDigits[i] * multi) + carry) / 10;
		result.push_back(sum);
	}
	if(carry > 0){
		result.push_back(carry);
		carry = 0;
	}
	for(int i = 1; i < tam2 - 1; i++){
		multi = num.getDigit(i);
		int posSum = ini;
		for(int j = 0; j < tam1 - 1; j++){
			sum = ((vecDigits[i] * multi) + carry) % 10;
			carry = ((vecDigits[i] * multi) + carry) / 10; 
			sum += carry2;
			carry2 = sum / 10;
			sum %= 10;
			if(posSum > result.size() - 1){
				result.push_back(sum);
				if(carry2 != 0){
					result.push_back(carry2);
					carry2 = 0;
				}
			}
			else{
				sum += result[posSum] + carry2;
				carry2 = sum / 10;
				sum %= 10;
				result[posSum] = sum;
			}
			posSum += 1;
		}
		if(carry > 0)
			result.push_back(carry);
		ini += 1;	
	}
	vecDigits = vector<int>(result);
}

/*
Operación addDigit

Entrada: un BigInteger y un entero positivo

Salida: un BigInteger

Descripción: la operación añade un dígito al principio de un BigInteger pasado como parámetro
*/
void BigInteger::addDigit(int digit){
	vecDigits.push_front(digit);
}
pair<string, string> BigInteger::divMod(BigInteger& num){
	BigInteger divisor(num);
	string div, ini;
	pair<BigInteger, BigInteger> ans;
	char digit;
	int i;
	int tam1 = vecDigits.size(). tam2 = num.getSize(), i = 0;
	int signo = vecDigits[tam1 - 1] * num.getDigit(tam2 - 1);
	while(i < tam2 - 1){
		digit = vecDigits[tam1 - 2 - i] + '0';
		ini += digit;
		i += 1;
	}
	BigInteger residuo(ini);
	if(residuo < num){
		digit = vecDigits[tam1 - 2 - i] + '0';
		ini += digit;
		residuo.addDigit(digit);
		i += 1;
	}
	while(residuo <= (*this)){
		int multi = 0;
		BigInteger divisor(num);
		while(divisor <= residuo){
			divisor.add(num);
			multi += 1;
		}
		divisor.substract(num);
		residuo.substract(divisor);
		digit = '0' + multi;
		div += digit;
		digit = vecDigits[tam1 - 2 - i];
		residuo.addDigit(digit);
		i += 1;
	}
	string cad = residuo.toString();
	ans.first = digit;
	ans.second = cad;
	return ans;

}
/*
Operación quotient

Entrada: dos BigInteger

Salida: divide un BigInteger entre otro

Descripción: hace un llamado a la función divMod y realiza esa operación sobre el primer BigInteger pasado como parámetro
y toma de la pareja el primer elemento 
*/

void BigInteger::quotient(BigInteger& num){
	if((*this) < num){
		vecDigits.clear();
		vecDigits.push_back(0);
		vecDigits.push_back(1);
	}
	else if((*this) == num){
		vecDigits.clear();
		vecDigits.push_back(1);
		vecDigits.push_back(1);
	}
	else{
		num.cambiarSigno();
		if((*this) < num){
			vecDigits.clear();
			vecDigits.push_back(0);
			vecDigits.push_back(1);
			num.cambiarSigno();
		}
		else if((*this) == num){
			vecDigits.clear();
			vecDigits.push_back(1);
			vecDigits.push_back(1);
			num.cambiarSigno();
		}
		else{
			num.cambiarSigno();
			pair<string, string> pareja = this->divMod(num);
			BigInteger ans(pareja.first);
			(*this) = ans;
		}

	}

}
/*
Operación remainder

Entrada: dos BigInteger

Salida: le saca módulo de una de una división un BigInteger entre otro

Descripción: hace un llamado a la función divMod y realiza esa operación sobre el primer BigInteger pasado como parámetro
y toma de la pareja el segundo elemento 
*/

void BigInteger::remainder(BigInteger& num){
	if((*this) == num){
		vecDigits.clear();
		vecDigits.push_back(0);
		vecDigits.push_back(1);
	}
	else if(num < (*this)){
		pair<string, string> pareja = this->divMod(num);
		BigInteger ans(pareja.second);
		(*this) = ans;
	}
}

/*
Operación pow

Entrada: un BigInteger y un entero

Salida: un BigInteger

Descripción: multiplica un BigInteger pasado como parámetro por el mismo una cantidad n de veces que es el número
que se pasa.
*/

void BigInteger::pow(int potencia){
	for(int i = 0; i < potencia; i++)
		this->product((*this));
}

/*
Sobrecarga +

Entrada: dos BigInteger

Salida: un BigInteger

Descripción: crea una nueva variable que es la copia del primer BigInteger pasado como parámetro y aplica la función
add con la segunda variable pasada como parámetro sobre esa nueva variable y retorna un BigInteger que es el
resultado de aplicar esta función.
*/

BigInteger BigInteger::operator +(BigInteger& num){
	BigInteger ans((*this));
	ans.add(num);
	return ans;
}
/*
Sobrecarga -

Entrada: dos BigInteger

Salida: un BigInteger

Descripción: crea una nueva variable que es la copia del primer BigInteger pasado como parámetro y aplica la función
substract con la segunda variable pasada como parámetro sobre esa nueva variable y retorna un BigInteger que es el
resultado de aplicar esta función.
*/
BigInteger BigInteger::operator -(BigInteger& num){
	BigInteger ans((*this));
	ans.substract(num);
	return ans;
}

/*
Sobrecarga *

Entrada: dos BigInteger

Salida: un BigInteger

Descripción: crea una nueva variable que es la copia del primer BigInteger pasado como parámetro y aplica la función
product con la segunda variable pasada como parámetro sobre esa nueva variable y retorna un BigInteger que es el
resultado de aplicar esta función.
*/
BigInteger BigInteger::operator *(BigInteger& num){
	BigInteger ans((*this));
	ans.product(num);
	return ans;
}

/*
Sobrecarga /

Entrada: dos BigInteger

Salida: un BigInteger

Descripción: crea una nueva variable que es la copia del primer BigInteger pasado como parámetro y aplica la función
quotient con la segunda variable pasada como parámetro sobre esa nueva variable y retorna un BigInteger que es el
resultado de aplicar esta función.
*/

BigInteger BigInteger::operator /(BigInteger& num){
	BigInteger ans((*this));
	ans.quotient(num);
	return ans;
}
/*
Sobrecarga /

Entrada: dos BigInteger

Salida: un BigInteger

Descripción: crea una nueva variable que es la copia del primer BigInteger pasado como parámetro y aplica la función
remainder con la segunda variable pasada como parámetro sobre esa nueva variable y retorna un BigInteger que es el
resultado de aplicar esta función.
*/

BigInteger BigInteger::operator %(BigInteger& num){
	BigInteger ans((*this));
	ans.remainder(num);
	return ans;
}
/*
Función sumarListaValores

Entrada: una lista de BigInteger

Salida: un BigInteger

Descripción: recorre una lista de BigInteger y va sumando los BigInteger dentro de la lista 
y retorna al final un BigInteger que es la suma de todos los BigInteger dentro de la lista.
*/

BigInteger BigInteger::sumarListaValores(list<BigInteger>& b){
	list<BigInteger>::iterator it = b.begin();
	BigInteger ans((*it));
	it++;
	while(it != b.end()){
		ans.add((*it));
		it++;
	}
	return ans;


}
/*
Función multiplicarListaValores

Entrada: una lista de BigInteger

Salida: un BigInteger

Descripción: recorre una lista de BigInteger y va multiplicando los BigInteger dentro de la lista 
y retorna al final un BigInteger que es la multiplicación de todos los BigInteger dentro de la lista.
*/
BigInteger BigInteger::multiplicarListaValores(list<BigInteger>& b){
	list<BigInteger>::iterator it = b.begin();
	BigInteger ans((*it));
	it++;
	while(it != b.end()){
		ans.product((*it));
		it++;
	}
	return ans;
}

