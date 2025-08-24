#include <stdio.h>

int f(int m, int n){
	int i, result = 0;
	if(n > m){
		n = m;
	}
	if(n <= 1){
		result = 1;
	}
	else{
		for(i = 2; i <= n; i++){
			result += f(m - i, i);
		}
		result++;
	}
	return result;
}

int main(void){
	int m, n;
	scanf("%d%d",&m, &n);
	printf("%d\n",f(m, n));
	return 0;
}
/*******************************************

f(0, 0) = f(1, 1) = 1
f(m, m + x) = f(m, m) (x > 0)
f(m, n) = 1 + ��[2 <= i <= n] f(m - i , i)
���ƹ�����������ζ��������f(1, 0)����ʽ 

********************************************/
