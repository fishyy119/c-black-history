#include <stdio.h>

int main(void){
	int n, a[9][100] = {0}, i, j, l, k;  //  a[x][0]�洢a[x]����Ч���ָ���, a[x]��Ӧx + 1λ��, i j l����ѭ��, k���ڼ��� 
	scanf("%d",&n);
	a[0][0] = 9;  //  һλ����Ӧ����׵� 
	for(i = 1; i < 10; i++){
		a[0][i] = i;
	}
	if(n == 0){
		printf("0\n");
	}
	else{
		for(i = 0; i < n - 1; i++){  //  ����λ����1��n���� 
			k = 0;
			for(j = 1; j <= a[i][0]; j++){  //  ��a[i]ÿ���������μ�0 ~ 9 
				for(l = 0; l < 10; l++){
					if((a[i][j] * 10 + l) % ((i + 2) * (i + 2)) == 0){
						k++;
						a[i + 1][k] = a[i][j] * 10 + l;
					}
				}
			}
			a[i + 1][0] = k;
		}
		printf("%d\n",a[n - 1][0]);
	}	
	return 0;
}
