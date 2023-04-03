#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

class Pista {
public:
    string number;
    int correctos, incorrectos;
    
    Pista() {}
    
    Pista(string numero, int correct, int wrong) 
    {
        number = numero;
        correctos = correct;
        incorrectos = wrong;
    }
};

string numeroACad(int num) 
{
    int i = num, n = i % 10;
    char digit = '0' + n;
    string ans = "";
    ans += digit;
    
    while(ans.size() < 4) 
    {
        if(n != i) {		
            i /= 10;
            n = i % 10;
            digit = '0' + n;
            ans = digit + ans;
        }
        else {
            ans  = '0' + ans;
        }
    }
    return ans;
}

int main() 
{
    int cases, cantNums, correctos, incorrectos, temp, x;
    string numero, numGen;
    vector<Pista> numbers;
	
    scanf("%d",&cases);
    for(int i = 0; i < cases; i++) 
    {
        scanf("%d", &cantNums);
        for(int j = 0; j < cantNums; j++)
        {
            scanf("%d %d/%d",&temp, &correctos, &incorrectos);
            numero = numeroACad(temp);
            Pista pista(numero, correctos,incorrectos);
            numbers.push_back(pista);		
        }
        bool flag = true;
        int k = 0;
        string ans = "";
        while(k < 10000 && flag) 
        {
            numGen = numeroACad(k);
            vector<Pista>::iterator it = numbers.begin();
            bool flag2 = true;
            while(it != numbers.end() && flag2) 
            {
                numero = (*it).number;
                correctos = (*it).correctos;
                incorrectos = (*it).incorrectos;
                int y = 0;
                vector<int> posUs;
                while(y < 4 && correctos >= 0) 
                {
                    if(numero[y] == numGen[y]) 
                    {
                        correctos -= 1;
                    }
                    else 
                    {
                        string::iterator it = find(numero.begin(), numero.end(),numGen[y]);
                        int pos = it - numero.begin();
                        if (it != numero.end() && numero[pos] != numGen[pos])
                        {
                            incorrectos -= 1;
                            posUs.push_back(pos);
                        }
                    }
                    y += 1;
                }
                for (y = 0; y < posUs.size(); y++) 
				{
    				for (x = y + 1; x < posUs.size(); x++) 
    				{
        				if (posUs[y] == posUs[x]) 
        				{
            				incorrectos += 1;
            				posUs[x] = -1; // marcar como ya contada
        				}
    				}
				}
                if(correctos != 0 || incorrectos != 0) 
                {
                    flag2 = false;
                }
                it++;		
            }
            if(flag2 && ans == "") 
            {
                ans = numGen;
            }
            else if(flag2) 
            {
                flag = false;
                cout << "indeterminate" << endl;
            }
            k += 1;
        }
        if(flag && ans != "") 
        {
            cout << ans << endl;
        }
        else if(flag && ans == "") 
        {
            cout << "impossible" << endl;
        }
        numbers.clear();
    }
    return 0;
}