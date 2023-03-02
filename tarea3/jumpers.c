#include <stdio.h>
#include <stdlib.h>


int main()
{
	int num, i, j, flag, cont;
	int arr[3000];
	while(scanf("%d",&num)!= EOF)
	{	
		for(i = 0; i < num; i++)
		{
			scanf("%d", &arr[i]);
		}
		i = num - 1;
		flag = 1;
		while(i > 0 && flag == 1)
		{
			j = num - 1;
			
			while(j > 0)
			{
				cont = abs(arr[j] - arr[j - 1]);
				j -= 1;
				if (cont == i)
				{
					j = -1;
				}
			}
			if (j == 0)
			{
				flag = 0;
				printf("Not jolly\n" );
			}
			i -= 1;
		}
		if (flag == 1)
		{
			printf("Jolly\n");
		}
	}
	return 0;
}