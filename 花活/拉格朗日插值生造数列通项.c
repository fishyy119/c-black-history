#include <stdio.h>

struct raNum{
	int u; // ���� 
	int d; // ��ĸ 
};

int calFactor(int n, int m){ // nΪ��������mΪ������1Ϊ��λ 
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
	printf("������������(С��10)��");
	scanf("%d", &n);
	printf("�������и����ֵ���Կո�ָ");
	for(i = 0; i < n; ++i){
		scanf("%d", &num[i]);
		factor[i] = calFactor(n + 1, i + 1);
	}
	printf("ͨ�ʽ��f(x)=");
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
