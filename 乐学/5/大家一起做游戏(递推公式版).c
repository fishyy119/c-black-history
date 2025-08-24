#include <stdio.h>

int m,n;

int f(int x){
	if(x == 1){
		return 0;
	}
	else{
		return (f(x - 1) + m) % x;
	}
}

int main(void){	 
	scanf("%d%d",&n,&m);
	printf("The left child is NO %d.\n",f(n) + 1);
	return 0;
}
