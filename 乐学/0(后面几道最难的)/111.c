#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void){
	int a, i;
	for(i = 0; i < 4; i++){
		printf("1 ");
		srand(time(0) ^ clock());
		
		a = rand();
		printf("%d\n", a/* % 3 + 2017 + (a % 3 == 0)*/);
	}
	return 0;
}
