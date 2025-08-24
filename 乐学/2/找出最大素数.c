#include <stdio.h>
#include <math.h>

int main(void){
	int range,pToF,max;
	int i,j;
	scanf("%d",&range);
	for(i = 1; i <= range; i++){
		pToF = 1;
		for(j = 2; j < (int)sqrt(i); j++){
			if(!(i % j)){
				pToF = 0;
			}	
		}
		if(pToF){
			max = i;
		}
	}
	printf("The max prime number is %d.\n",max);
	return 0;
}
