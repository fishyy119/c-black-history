#include <stdio.h>
#include <math.h>
double sum = 0.0;

double f(int x){
	if(x == 1){
		sum += 1;
		return sum;
	}
	else{
		sum += pow(-1, x) / x;
		f(x - 1);
	}
}

int main(void){
	int n;
	scanf("%d",&n);
	if(n == 1 || n == 0){
		printf("%d\n",n);
	}
	else{
		printf("%lf\n",f(n));
	}
	return 0;
}
