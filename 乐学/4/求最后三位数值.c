#include <stdio.h>

int main(void){
	int a, atemp, n, flag = 0;
	scanf("%d%d",&a,&n);
	atemp = a;
	a /= a;
	for(; n > 0; n--){
		a *= atemp;
		if(a / 100){
			a %= 1000;
			flag = 1;
		}
	}
	if(flag){
		printf("The last 3 numbers is %03d.\n",a);
	}
	else{
		printf("The last 3 numbers is %d.\n",a);
	}		
	return 0;
}
