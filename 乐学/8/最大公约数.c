#include <stdio.h>

int gcd(int x, int y){  //  x > y 
	if(x >= y && x % y == 0){
		return y;
	}
	else if(y > x){
		gcd(y, x);
	}
	else{
		gcd(y, x % y);
	}
}

int main(void){
	int m, n;
	scanf("%d%d",&m, &n);
	printf("%d\n",gcd(m, n));
	return 0;
}
