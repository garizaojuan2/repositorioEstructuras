#include <stdio.h>
void solve(int ejeX,int ejeY, int puntoX,int puntoY){
	if (puntoX > ejeX && puntoY > ejeY){
		printf("NE\n");
	}
	else if (puntoX < ejeX && puntoY > ejeY){
		printf("NO\n");
	}
	else if (puntoX < ejeX && puntoY < ejeY){
		printf("SO\n");
	}
	else if (puntoX > ejeX && puntoY < ejeY){
		printf("SE\n");
	}
	else{
		printf("divisa\n");
	}
}
int main(){
	int cases, i, bordeX, bordeY, resX, resY;
	scanf("%d",&cases);
	while(cases != 0){
		scanf("%d",&bordeX);
		scanf("%d",&bordeY);
		for(i = 0; i < cases; i++){
			scanf("%d",&resX);
			scanf("%d",&resY);
			solve(bordeX,bordeY,resX,resY);
		}
		scanf("%d",&cases);
	}

	return 0;
}