#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;

string minAMay(const string cad)
{
	string ans;
	char letra;
	int i;
	for(i = 0; i < cad.size(); i++)
	{
		letra = cad[i];
		if(letra <= 'z' && letra >= 'a')
		{
			letra -= 32;
		}
		ans += letra;
	}
	return ans;
}
class team
{
public:
	string nombre;
	int golesA, golesR, pj, goalDiff, puntos;
	double per100;
	team();

   team(string name)
   {
    nombre = name;
	puntos = 0;
	golesA = 0;
	golesR = 0;
	pj = 0;
	goalDiff = 0;
   }
   bool operator ==(const team &equipo)
	{
		bool ans = false;
		if (equipo.nombre == nombre)
		{	
		ans = true;
		}

		return ans;
	}
   bool operator <(const team &equipo)
	{
		bool ans;
		if(puntos != equipo.puntos)
		{
			ans = puntos > equipo.puntos;
		}
		else if(goalDiff != equipo.goalDiff)
		{
			ans = goalDiff > equipo.goalDiff;
		}
		else if(golesA != equipo.golesA)
		{
			ans = golesA > equipo.golesA;
		}
		else
		{
			string equipo1 = minAMay(nombre);
			string equipo2 = minAMay(equipo.nombre);
			ans = equipo1 < equipo2;
		}
	return ans;
	}
	bool comprobar(const team &equipo)
	{
		bool ans = true;
		if(puntos != equipo.puntos)
		{
			ans = false;
		}
		else if(goalDiff != equipo.goalDiff)
		{
			ans = false;
		}
		else if(golesA != equipo.golesA)
		{
			ans = false;
		}
		return ans;
	}
};

int main()
{
	int numGames, numTeams, i, j, points, matches, sufG, scG, diffGoals;
	string equipo, name, line, num;
	vector<team> listTeams;
	double percentage;
	vector<team>:: iterator posEq1, posEq2, it, eq2, ant;
	scanf("%d %d",&numTeams, &numGames);
	cin.ignore();
	while(numTeams != 0 || numGames != 0)
	{
		for(i = 0; i < numTeams; i++)
		{
			cin >> equipo;
			cin.ignore();
			team eq(equipo);
			listTeams.push_back(eq);
		}
		string equipo1, equipo2;
		int goles1, goles2;
		for(i = 0; i < numGames; i++)
		{
			cin >> equipo1;
			cin.ignore();
			scanf("%d - %d",&goles1,&goles2);
			cin.ignore();
			cin >> equipo2;
			cin.ignore();
			// equipo 1
			posEq1 = find(listTeams.begin(), listTeams.end(), equipo1);
			(*posEq1).golesA += goles1;
			(*posEq1).golesR += goles2;
			(*posEq1).goalDiff += goles1;
			(*posEq1).goalDiff -= goles2;
			(*posEq1).pj += 1;
			
			// equipo 2
			posEq2 = find(listTeams.begin(), listTeams.end(), equipo2);
			(*posEq2).golesA += goles2;
			(*posEq2).golesR += goles1;
			(*posEq2).goalDiff += goles2;
			(*posEq2).goalDiff -= goles1;
			(*posEq2).pj += 1;

			if(goles1 > goles2)
			{
				(*posEq1).puntos += 3;
			}
			else if(goles1 < goles2)
			{
				(*posEq2).puntos += 3;
			}
			else
			{
				(*posEq1).puntos += 1;
				(*posEq2).puntos += 1;
			}
		}
		sort(listTeams.begin(), listTeams.end());
		i = 0;
		
		
		char noAplica[4]= "N/A";
		while(i < listTeams.size())
		{	
			const char *nombreEq = listTeams[i].nombre.c_str();
			points = listTeams[i].puntos;
			matches = listTeams[i].pj;
			scG = listTeams[i].golesA;
			sufG = listTeams[i].golesR;
			diffGoals = listTeams[i].goalDiff;

			if(i == 0)
			{
				if(matches == 0)
				{

					printf("%2d.%16s%4d%4d%4d%4d%4d%7s\n", i + 1, nombreEq, points,matches, scG, sufG, diffGoals, noAplica);
				}
				else
				{
					double result1 = points, result2 = matches*3;
					percentage = (result1/(result2))*100;
					printf("%2d.%16s%4d%4d%4d%4d%4d%7.2f\n", i + 1, nombreEq, points,matches, scG, sufG, diffGoals, percentage);
				}
				j = -1;

			}
			else if(listTeams[i].puntos != listTeams[j].puntos || listTeams[i].goalDiff != listTeams[j].goalDiff ||listTeams[i].golesA != listTeams[j].golesA)
			{
				if(matches > 0)
				{
					
					
					double result1 = points, result2 = matches*3;
					percentage = (result1/(result2))*100;
					printf("%2d.%16s%4d%4d%4d%4d%4d%7.2f\n", i + 1, nombreEq, points,matches, scG, sufG, diffGoals, percentage);	
				}
				else if(matches == 0)
				{
					
					printf("%2d.%16s%4d%4d%4d%4d%4d%7s\n", i + 1, nombreEq, points,matches, scG, sufG, diffGoals, noAplica);
				}
			}
			else
			{
				if(matches > 0)
				{
					printf("%19s%4d%4d%4d%4d%4d%7.2f\n",nombreEq, points,matches, scG, sufG, diffGoals, percentage);
				}
				else
				{
					printf("%19s%4d%4d%4d%4d%4d%7s\n", nombreEq, points,matches, scG, sufG, diffGoals, noAplica);
				}
			}
			j++;
			i++;
		}
			
		scanf("%d %d",&numTeams, &numGames);
		cin.ignore();
		if(numTeams != 0 || numGames != 0)
		{
			printf("\n");
		}
		listTeams.clear();
	}	
	return 0;
}