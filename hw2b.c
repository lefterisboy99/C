#include <stdio.h>


int main(){
	int x;
	int y;
	int i;
	int j;
	int l;
	j=1;
	scanf("%d",&x);
	while (x!=0) {
		y=1;
		for (i=2;i<=j/2;i++){
			if (j%i==0){
				y=0;
				break;
			}
		}
		if (j!=1){
			if (y){
				x=x-1;
				printf("%d\n",j);
			}
		}
		j++;
	}
	return 0;
}
