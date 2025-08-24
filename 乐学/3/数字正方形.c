#include <stdio.h>

int main(void){
	int n,i,j;
	scanf("%d",&n);
	for(i = 0; i <= n * (n - 1); i += n){
		for(j = 1; j <= n; j++){
			printf("%3d",i + j);
		}
		printf("\n");
	}
	return 0;
}
