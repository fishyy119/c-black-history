#include <stdio.h>

int main(void){
	int i, j;
	for(i = 1; i <= 9; i++){
		printf("%4d", i);
	}
	printf("\n--------------------------------------\n");
	for(i = 1; i <= 9; i++){
		for(j = 1; j <= 9; j++){
			if(i + j >= 10){
				printf("%4d", (10 - i) * j);
			}
			else{
				printf("    ");
			}
		}
		printf("\n");
	}
	return 0;
}
