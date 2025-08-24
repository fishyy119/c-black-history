#include <stdio.h>
#include <math.h>
#define MAX 10000

int judgeTriangle(int a, int b, int c){ // a <= b <= c
	if(a + b > c){
		return 1;
	}
	return 0;
}

double Heron(int a, int b, int c){
	double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main(void){
	int a, b, c;
	for(a = 1; a <= MAX; a++){
		if(a % 10 == 0){
			printf("%d\r", a);
		}
		for(b = a; b <= MAX; b++){
			for(c = b; c <= MAX; c++){
				if(judgeTriangle(a, b ,c)){
					if(fabs(Heron(a, b ,c) - a - b - c) < 0.00001)
						printf("%d.%d.%d:%lf\n", a, b, c, Heron(a, b ,c));
				}
			}
		}
	}
	return 0;
}
