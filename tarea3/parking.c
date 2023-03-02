#include <stdio.h>

int main(){
	int cases, i, j, stores, mayor, menor, promedio, pos, ans;
	scanf("%d",&cases);
	for(i = 0; i < cases; i++){
		scanf("%d",&stores);
		mayor = 0;
		menor = 100;
		for(j = 0; j < stores; j++){
			scanf("%d",&pos);
			promedio += pos;
			if (pos > mayor){
				mayor = pos;
			}
			if (pos < menor){
				menor = pos;
			}
		}			
		promedio /= stores;
		ans = 2*(promedio - menor) + 2*(mayor - promedio);
		printf("%d\n",ans);

		
	}
	return 0;
	
}