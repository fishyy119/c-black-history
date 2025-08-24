#include <stdio.h>
#include <math.h>

int main(void){
	int n,i,j;
	scanf("%d",&n);
	for(i = 1; i <= 2 * n - 1; i++){
		for(j = 1; j <= (int)fabs(n - i) % n; j++){   /* 左侧空位数等于( |n - 行数| % n) */
			printf("  ");
		}
		for(j = n; j >= (int)fabs(n - i) % n + 1; j--){    /* 每行的最小数等于( 左侧空位数 + 1) */ 
			printf("%-2d",j);
		}
		for(j += 2; j <= n; j++){
			printf("%-2d",j);
		}
		printf("\n");
	}
	return 0;
}
