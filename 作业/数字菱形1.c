#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// 12345654321

int main(void){
	int n, i, j;
	scanf("%d", &n);
	for(i = 1; i <= 2 * n - 1; i++){
		for(j = 1; j <= 2 * n; j++){
			if(j == 2 * n - abs(n - i)){
				printf("\n");
				break;
			}
			else if(j <= abs(n - i)){
				printf(" ");
			}
			else{
				printf("%d", n - abs(j - n) - abs(i - n));
			}
		}
	}
	system("PAUSE");
	return 0;
}
