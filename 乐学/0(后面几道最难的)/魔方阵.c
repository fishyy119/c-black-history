#include <stdio.h>

int main(void){
	int n, num = 1, i, reverse = 1;
	scanf("%d",&n);
	int *a = (int*)malloc(sizeof(int) * n * n);
	for(i = 0; i < n - reverse / 4; i++){
		*(a + i) = num;
		num++;
	}
	for(; i < )
}
