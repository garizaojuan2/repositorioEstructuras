#include <stdio.h>

int main()
{
	int cases, i, n, j, arr1[100001], arr2[100001], flag, cont, ini, flag2, ciclo;
	scanf("%d",&cases);
	for (i = 0; i < cases; i++)
	{
		scanf("%d", &n);
		for(j = 0; j < n; j++)
		{
			scanf("%d",&arr1[j]);
		}
		for(j = 0; j < n; j++)
		{
			scanf("%d",&arr2[j]);
		}
		j = 0;
		flag = 1;
		ini = 1;
		while (j < n && flag == 1)
		{
			if (arr1[j] >= arr2[j])
			{
				cont = arr1[j] - arr2[j];
				ciclo = j + 1;
				flag2 = 1;
				while( j != ciclo && flag2 == 1)
				{
					cont += arr1[ciclo] - arr2[ciclo];
					if (ciclo == n - 1)
					{
						ciclo += 1;
						ciclo %= n;
					}
					else
					{
						ciclo += 1;
					}
					if (cont < 0)
					{
						flag2 = 0;
						ciclo = j;
					}
				}
			}
			j += 1; 
			if (flag2 == 1)
			{

				flag = 0;
				printf("Case %d: ",i + 1);
				printf("Possible from station %d\n", ini);
			}
			ini += 1;
		}
		if (flag == 1)
		{
			printf("Case %d: Not possible\n",i + 1);
		}		
	}
	return 0;
}