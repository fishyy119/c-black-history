#include <stdio.h>

int main(void){
	int n,x;
	scanf("%d",&n);
	x = 1;
	n -= 1;
	while(n >= 1){
		x = (x + n) * 2;
		n--;
	}
	if(x == 1){
		printf("The monkey got %d peach in first day.\n",x);
	}
	else{
		printf("The monkey got %d peaches in first day.\n",x);		
	}
	return 0;
}
