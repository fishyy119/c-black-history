#include <stdio.h>
#include <math.h>

int prime(int x){
	int j;
	for(j = 2; j < (int)sqrt(x) + 1; j++){
		if(x % j == 0){
			return 0;  // ²»ÊÇ 
		}		  
	}
	return 1;  // ÊÇ 
}

int main(void){
	int a, b;
	scanf("%d%d",&a,&b);
	if(a % 2 == 0){
		a += 1;
	}
	for(; a < b - 2; a += 2){
		if(prime(a)){
			if(prime(a + 2)){
				printf("%d,%d\n", a, a + 2);
			}
		}
	}	
	return 0;
}
