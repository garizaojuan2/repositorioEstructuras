#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 
int main()
{
	int numCarreras, pilots, i, j, posPil, numSisPunt, puestosPrem, puntos, k, pos;
	vector<vector<int>> posCarreras;
	vector<vector<int>> sisPunt;
	cin >> numCarreras;
	cin >> pilots;
	while(pilots != 0 || numCarreras != 0)
	{
		for(i = 0; i < numCarreras; i++)
		{
			vector<int> carrera;  
			for(j = 0; j < pilots; j++)
			{
				cin >> posPil;
				carrera.push_back(posPil);
			}
			posCarreras.push_back(carrera);
		}
		cin >> numSisPunt;
		for(i = 0; i < numSisPunt; i++)
		{
			vector<int> sistema(pilots,0);
			cin >> puestosPrem;
			for(j = 0; j < puestosPrem; j++)
			{
				cin >> puntos;
				sistema[j] = puntos;
			}
			sisPunt.push_back(sistema);
		}
		for(i = 0; i < numSisPunt; i++)
		{
			vector<int> puntuaciones(pilots, 0);
			
			for(j = 0; j < numCarreras; j++)
			{
				for(k = 0; k < pilots; k++)
				{
					pos = posCarreras[j][k];
					puntuaciones[k] += sisPunt[i][pos - 1];
				}
			}
			vector<int> ganadores = {puntuaciones[0], 1};
			for(j = 1; j < pilots; j++)
			{
				if (ganadores[0] < puntuaciones[j])
				{
					ganadores = {puntuaciones[j], j + 1};
				}
				else if(ganadores[0] == puntuaciones[j])
				{
					ganadores.push_back(j + 1);
				}
			}
			for(j = 1; j < ganadores.size(); j++)
			{
				if (j + 1 < ganadores.size())
				{
					cout << ganadores[j] << " ";
				}
				else
				{
					cout << ganadores[j] << endl;
				}
			}
		}	
		posCarreras.clear();
		sisPunt.clear();
		cin >> numCarreras;

		cin >> pilots;
	}

	return 0;
}



	
