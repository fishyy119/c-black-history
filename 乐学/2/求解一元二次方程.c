#include <stdio.h>
#include <math.h>

int main(void){
	int a,b,c;
	double delta;
	scanf("%d%d%d",&a,&b,&c);
	if(!(a || b)){                /*非方程*/
		printf("Input error!\n");
	}
	else if(!a && b){             /*为一次方程*/ 
		if(c != 0){
			printf("x=%.6lf\n",-1.0 * c / b);
		}
		else{
			printf("x=0.000000\n");
		}
	}
	else{                         /*为二次方程*/
		delta = b * b - 4.0 * a * c;
		if(delta == 0){
			int c =  -1.0 * b / 2 / a;
			if(c){
				printf("x1=x2=%.6lf\n",-1.0 * b / 2 / a);
			}
			else{
				printf("x1=x2=0.000000\n");
			}
		}
		else if(delta > 0){
			printf("x1=%.6lf\n",(-1.0 * b + pow(delta,0.5))/ 2 / a);
			printf("x2=%.6lf\n",(-1.0 * b - pow(delta,0.5))/ 2 / a);
		}
		else if(delta < 0){
			if(-1.0 * b / 2 / a != 0){
				printf("x1=%.6lf%+.6lfi\n",-1.0 * b / 2 / a,pow(-1 * delta,0.5) / 2 / a);
				printf("x2=%.6lf%+.6lfi\n",-1.0 * b / 2 / a,-1 * pow(-1 * delta,0.5) / 2 / a);
			}
			else{
				printf("x1=%.6lfi\n",pow(-1 * delta,0.5) / 2 / a);
				printf("x2=%+.6lfi\n",-1 * pow(-1 * delta,0.5) / 2 / a);
			}
			
		}
	}
	return 0;
}
