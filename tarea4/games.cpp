#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int cases, i, j, x = 1;
	cin >> cases;
	string name, mayor, menor, cad, suma, suma2;
	while(cases != 0)
	{
		vector<string> vecNames;
		
		for(i = 0; i < cases; i++)
		{
		cin >> name;
		vecNames.push_back(name);
		}
		sort(vecNames.begin(), vecNames.end());
		menor = vecNames[(cases/2) - 1];
		mayor = vecNames[cases/2];
		i = 0;
		j = 0;
		cad = "";
		suma = cad;
		//cout << "Caso #" << x << endl;
		//cout << "El menor es:" << menor << endl;
		//cout << "El mayor es:" << mayor << endl;
		// x += 1;
		while(i < menor.size() && j < mayor.size())
		{

			if(menor[i] != mayor[j] && menor[i] != 'Z' && i + 1 != menor.size())
			{
				suma += (menor[i] + 1);				
				if ((suma < mayor && suma >= menor))
				{
					cad = suma;
					i = menor.size();
				}	
				else
				{
					cad += menor[i];
					i += 1;
					while(i < menor.size())
					{
						if(menor[i] != 'Z' && i + 1 != menor.size())
						{
							
							cad += (menor[i] + 1);
							i = menor.size();
						}
						else if(menor[i] != 'Z' && i + 1 == menor.size())
						{
							cad += menor[i];
							i = menor.size();
						}
						else
						{
							cad += menor[i];
						}
						i += 1; 
					}
				}
			}
			else if(menor[i] != mayor[j] && menor[i] != 'Z' && i + 1 == menor.size())
			{
				cad += menor[i];
			}
			else if(menor[i] == mayor[j])
			{
				cad += menor[i];
				suma = cad;
				j += 1;
			}
			i += 1;
			
		}
		cin >> cases;

		cout << cad << endl;


	}
}