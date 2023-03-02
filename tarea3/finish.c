#include <stdio.h>

int main()
{
    int cases, i, k, n, j, gasEst[100001], gasNec[100001], flag, gasoDispo, ini, flag2, ciclo;
    scanf("%d", &cases);
    for (i = 0; i < cases; i++)
    {
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &gasEst[j]);
        }
        for (j = 0; j < n; j++)
        {
            scanf("%d", &gasNec[j]);
        }
        j = 0;
        flag = 1;
        ini = 1;
        while (j < n && flag == 1)
        {
            if (gasEst[j] >= gasNec[j])
            {
                gasoDispo = gasEst[j] - gasNec[j];
                ciclo = j + 1;
                flag2 = 1;
                while (j != ciclo && flag2 == 1)
                {
                    gasoDispo += gasEst[ciclo] - gasNec[ciclo];
                    if (gasoDispo < 0)
                    {
                        flag2 = 0;
                    }

                    ciclo += 1;
                    ciclo %= n;
                }
            }
            j += 1;
            if (flag2 == 1)
            {
                gasoDispo = 0;
                for (k = 0; k < n; k++)
                {
                    gasoDispo += gasEst[k] - gasNec[k];
                }
                if (gasoDispo >= 0)
                {
                    flag = 0;
                    printf("Case %d: ", i + 1);
                    printf("Possible from station %d\n", ini);
                }
            }
            ini += 1;
        }
        if (flag == 1)
        {
            printf("Case %d: Not possible\n", i + 1);
        }
    }
    return 0;
}