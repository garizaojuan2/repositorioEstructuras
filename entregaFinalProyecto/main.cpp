#include <vector>
#include <string>
#include <iostream>
#include <list>

using namespace std;

class BigInteger
{
private:
    vector<int> vecDigits;

public:
    // Creación de prototipos de las funciones del TAD Big Integer
    BigInteger(string& number);
    BigInteger(const BigInteger& num);
    int getDigit(int pos);
    int getSize();
    bool operator ==(BigInteger& num);
    bool operator <(BigInteger& num);
    bool operator <=(BigInteger& num);
};

BigInteger::BigInteger(string& number){
    int tam = number.size();
    int digit, signo = 1;
    int i = tam - 1;
    int fin = 0;
    if(number[0] == '-'){
        signo = -1;
        fin = 1;
    }
    while (i >= fin) {
        digit = number[i] - '0';
        vecDigits.push_back(digit);
        i -= 1;
    }
    vecDigits.push_back(signo);
}

BigInteger::BigInteger(const BigInteger& num){
    vecDigits = vector<int>(num.vecDigits);
}

int BigInteger::getDigit(int pos){
    return vecDigits[pos];
}

int BigInteger::getSize(){
    return vecDigits.size();
}

bool BigInteger::operator ==(BigInteger& num){
    bool ans = true;
    if (vecDigits.size() != num.getSize() || (num.getDigit(num.getSize() - 1) != vecDigits[vecDigits.size() - 1])){
        ans = false;
    }
    else{
        int i = 0;
        while (i < vecDigits.size() && ans){
            if (vecDigits[i] != num.getDigit(i))
                ans = false;
            i += 1;
        }
    }
    return ans;
}

bool BigInteger::operator <(BigInteger& num){
    bool ans = false;
    if (vecDigits.size() != num.getSize()){
        if (vecDigits[vecDigits.size() - 1] > 0 && (num.getDigit(num.getSize() - 1) > 0))
            ans = vecDigits.size() < num.getSize();
        else if ((vecDigits[vecDigits.size() - 1] < 0 && (num.getDigit(num.getSize() - 1) < 0)))
            ans = vecDigits.size() > num.getSize();
        else if (((vecDigits[vecDigits.size() - 1] < 0 && (num.getDigit(num.getSize() - 1) > 0)) || (vecDigits[vecDigits.size() - 1] > 0 && (num.getDigit(num.getSize() - 1) < 0))))
            ans = vecDigits[vecDigits.size() - 1] < num.getDigit(num.getSize() - 1);
    }
    else{
        int i = vecDigits.size() - 2;
        while (i >= 0){
            if (vecDigits[i] != num.getDigit(i)){
                ans = vecDigits[i] < num.getDigit(i);
                i = 0;
            }
            i -= 1;
        }
    }
    return ans;
}

bool BigInteger::operator <=(BigInteger& num){
    bool ans = true;
    if (vecDigits.size() != num.getSize()){
        if (vecDigits[vecDigits.size() - 1] > 0 && (num.getDigit(num.getSize() - 1) > 0))
            ans = vecDigits.size() < num.getSize();
        else if ((vecDigits[vecDigits.size() - 1] < 0 && (num.getDigit(num.getSize() - 1) < 0)))
            ans = vecDigits.size() > num.getSize();
        else if (((vecDigits[vecDigits.size() - 1] < 0 && (num.getDigit(num.getSize() - 1) > 0)) || (vecDigits[vecDigits.size() - 1] > 0 && (num.getDigit(num.getSize() - 1) < 0))))
            ans = vecDigits[vecDigits.size() - 1] < num.getDigit(num.getSize() - 1);
    }
    else{
        int i = vecDigits.size() - 2;
        while (i >= 0) {
            if (vecDigits[i] != num.getDigit(i)){
                ans = vecDigits[i] < num.getDigit(i);
                i = 0;
            }
            i -= 1;
        }
    }
    return ans;
}

int main(){
    string num;
    int numCase = 1;
    while (cin >> num){

        string cad1, cad2, cad3, cad4;
        int i = 0;
        while (i < num.size() && num[i] != '.'){
            cad1 += num[i];
            i += 1;
        }
        i += 1;
        BigInteger val1(cad1);
        while (i < num.size()){
            cad2 += num[i];
            i += 1;
        }
        BigInteger deci1(cad2);
        cin >> num;
        i = 0;
        while (i < num.size() && num[i] != '.'){
            cad3 += num[i];
            i += 1;
        }
        i += 1;
        BigInteger val2(cad3);
        while(i < num.size()){
            cad4 += num[i];
            i += 1;
        }
        BigInteger deci2(cad4);
        cout << "Case " << numCase << ": ";
        if(val1 < val2)
            cout << "Smaller" << endl;
        else if (val2 < val1)
            cout << "Bigger" << endl;
        else{
        	if(cad2.size() == cad4.size()){
        		if(deci1 < deci2)
        			cout << "Smaller" << endl;
        		else
        			cout << "Bigger" << endl;
        	}
        	else{
        		i = 0;
        		int j = 0;
        		bool flag1 = true; 
        		bool flag2 = true;
        		while(i < deci1.getSize() && flag1){
        			if(deci1.getDigit(i) != 0){
        				flag1 = false;
        				i -= 1;
        			i += 1;
        			}
        		}
        		while(j < deci2.getSize() && flag2){
        			if(deci1.getDigit(i) != 0){
        				flag2 = false;
        				j -= 1;
        			j += 1;
        			}
        		}
        		if(flag1 && flag2)
        			cout << "Same" << endl;
        		else if(flag1 && !flag2)
        			cout << "Smaller" << endl;
        		else if(!flag1 && flag2)
        			cout << "Bigger" << endl;
        		else{
        			if(i < j || (deci1.getDigit(i) > deci2.getDigit(j) && i == j))
        				cout << "Bigger" << endl;
        			else if(i > j || (deci1.getDigit(i) < deci2.getDigit(j) && i == j))
        				cout << "Smaller" << endl;
        			else{
        				if(deci1 < deci2)
        					cout << "Smaller" << endl;
        				else if(deci2 < deci1)
        					cout << "Bigger" << endl;
        				else
        					cout << "Same" << endl;	
        			}

        		}

        	}
        }
        numCase += 1;
    }
    return 0;
}
