#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void){
	int a;
	srand((unsigned)time(NULL));
	a = rand();
	printf("%d\n", a % 3 + 2017 + (a % 3 == 0));
	sleep(5);
	return 0;
}
