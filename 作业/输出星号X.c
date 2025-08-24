#include <stdio.h>
#include <math.h>

int main(void){
	int n, i, j;
	scanf("%d", &n);
	for(i = 1; i <= 2 * n - 1; i++){
		for(j = 1; j <= 2 * n; j++){
			if(j == n + abs(n - i) + 1){
				printf("\n");
				break;
			}
			else if(j == i || j + i == 2 * n){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
	}
	return 0;
}
