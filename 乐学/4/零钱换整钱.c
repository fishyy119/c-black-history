#include <stdio.h>
#define oneCent 18
#define fiveCent 15
#define oneYuan 20
/* 不妨将厚度乘以十 *//* 下面还会将钱的价值乘以十 */
int main(void){
	int n, m1, m2, m3, flag = 1;
	scanf("%d",&n);
	for(m1 = 100 * n / 160 * 10; m1 <= 100 * n; m1 += 10){
		for(m2 = 100 * n / 160 * 12; m2 <= 20 * n; m2 += 12){
			for(m3 = 100 * n / 160 * 9; m3 <= 10 * n; m3 += 9){
				if((oneCent * m1 == fiveCent * m2) && (oneCent * m1 == oneYuan * m3)){
					if(m1 + 5 * m2 + 10 * m3 == 100 * n){
						printf("%d,%d,%d\n",m1,m2,m3);
						flag = 0;
					}
				}
			}
		}
	}
	if(flag){
		printf("No change.\n");
	}
	return 0;
}
