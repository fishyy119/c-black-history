#include <stdio.h>
#include <math.h>

int main(void){
	int n,i,j;
	scanf("%d",&n);
	for(i = 1; i <= 2 * n - 1; i++){
		for(j = 1; j <= (int)fabs(n - i) % n; j++){   /* ����λ������( |n - ����| % n) */
			printf("  ");
		}
		for(j = n; j >= (int)fabs(n - i) % n + 1; j--){    /* ÿ�е���С������( ����λ�� + 1) */ 
			printf("%-2d",j);
		}
		for(j += 2; j <= n; j++){
			printf("%-2d",j);
		}
		printf("\n");
	}
	return 0;
}
