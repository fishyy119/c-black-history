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
f(m, n) = 1 + Σ[2 <= i <= n] f(m - i , i)
递推过程中无论如何都不会出现f(1, 0)的形式 

********************************************/
