#include <stdio.h>

int main(void){
	int n,i,j;
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
		if(i == 1){
			for(j = 1; j <= 2 * n - 1; j++){   /* �����Ǻ� */
				printf("*");
			}
			printf("\n");
		}
		else{
			for(j = 1; j <= i - 1; j++){   /* ���ո� */
				printf(" ");
			}
			printf("*");
			for(j = 1; j <= (n - i) * 2 - 1; j++){   /* �м�ո� */
				printf(" ");
			}
			if(i == n){
				printf("\n");
			}
			else{
				printf("*\n");
			}
		}		
	}
	return 0;
}
