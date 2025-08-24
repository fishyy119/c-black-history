#include <stdio.h>

struct raNum{
	int u; // 分子 
	int d; // 分母 
};

int calFactor(int n, int m){ // n为项总数，m为序数，1为首位 
	int result = 1;
	int i, j;
	for(i = 1; i <= n; ++i){
		if(i == m){
			continue;
		}
		else{
			result *= (m -i);
		}
	}
	return result;
}

int main(void){
	int n, i, j, num[10], factor[10];
//	printf("%d\n", calFactor(6,1));
	printf("输入数列项数(小于10)：");
	scanf("%d", &n);
	printf("输入数列各项的值，以空格分割：");
	for(i = 0; i < n; ++i){
		scanf("%d", &num[i]);
		factor[i] = calFactor(n + 1, i + 1);
	}
	printf("通项公式：f(x)=");
	for(i = 0; i < n ; ++i){
		printf("(%d/%d)", num[i], factor[i]);
		for(j = 0; j < n; ++j){
			if(j == i){
				continue;
			}
			else{
				printf("(x-%d)", j + 1);
			}
		}
		if(i != n - 1){
			printf("+");
		}
	}
	return 0;
}
