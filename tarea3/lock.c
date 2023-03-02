#include <stdio.h>
int claves1(int posActual,  int key)
{
	int ans;
	if(posActual >= key)
	{
		ans = 360 - (9*(40 - (posActual - key)));
	}
	else{
		ans = 360 - 9*(key - posActual);
	}
	return ans;
}

int claves2(int posActual, int key)
{
	int ans;
	if (key >= posActual || posActual == 0)
	{
		ans = 9 * (key - posActual);
	}
	else
	{
		ans = 9 * (40 - posActual + key);
	}

	
	return ans;
}
int main(){
	int lock[4], ans, i;
	scanf("%d",&lock[0]);
	scanf("%d",&lock[1]);
	scanf("%d",&lock[2]);
	scanf("%d",&lock[3]);

	while (lock[0] != 0 || lock[1] != 0 || lock[2] != 0 || lock[3] != 0 )
	{
		ans = 1080;
		ans += claves1(lock[0],lock[1]);
		ans += claves2(lock[1],lock[2]);
		ans += claves1(lock[2],lock[3]);
		printf("%d\n",ans);
		scanf("%d",&lock[0]);
		scanf("%d",&lock[1]);
		scanf("%d",&lock[2]);
		scanf("%d",&lock[3]);
		
	}

	return 0;
}