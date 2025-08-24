#include <stdio.h>

int main(void){
	int f, x, time;
	scanf("%dhz%d%d",&f,&x,&time);
	printf("%d\n", (int)(f / 1024.0 / 8 * x * time * 60 * 2)); // f * 60 * 2  / 8 * x * time / 1024 也可以通过 
	return 0;
}
