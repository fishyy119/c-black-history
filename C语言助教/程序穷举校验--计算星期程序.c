#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

int isleap(int y, int m){
	if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
		if(m == 2){
			return 1;
		}
	}
	return 0;
}




int planA(int a, int b, int c){
	
	 
int  k;

//	scanf("%d%d%d", &a, &b, &c);
	int x = a - 1901;
	int t = x / 4;
	int y = 365 * x + t;
	int z = b - 1;
	int i = a % 4;

	if (a <= 1900) {
		printf("year is error.\n");
		return 0;
	}
	if (b < 1 || b > 12 ) {
		printf("month is error.\n");
		return 0;
	}
	if (i != 0 && (c > 28 || c < 1)) {
		printf("day is error.\n");
		return 0;
	}
	if (i == 0 && (c > 29 || c < 1)) {
		printf("day is error.\n");
		return 0;
	}
	if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12 ) && ( c > 31 || c < 1)) {
		printf("day is error.\n");
		return 0;
	}
	if ((b == 4 || b == 6 || b == 9 || b == 11 ) && ( c > 30 || c < 1)) {
		printf("day is error.\n");
		return 0;
	}













	if (a % 4 != 0)
		switch (z) {
			case 0:
				k = 0;
				break;
			case 1:
				k = 31;
				break;
			case 2:
				k = 59;
				break;
			case 3:
				k = 90;
				break;
			case 4:
				k = 120;
				break;
			case 5:
				k = 151;
				break;
			case 6:
				k = 181;
				break;
			case 7:
				k = 212;
				break;
			case 8:
				k = 243;
				break;
			case 9:
				k = 273;
				break;
			case 10:
				k = 304;
				break;
			case 11:

				k = 336;
				break;

		}

	int r = (y + k + c) % 7 + 1;
	if (a % 4 != 0)
		switch (z) {
			case 0:
				k = 0;
				break;
			case 1:
				k = 31;
				break;
			case 2:
				k = 59;
				break;
			case 3:
				k = 90;
				break;
			case 4:
				k = 120;
				break;
			case 5:
				k = 151;
				break;
			case 6:
				k = 181;
				break;
			case 7:
				k = 212;
				break;
			case 8:
				k = 243;
				break;
			case 9:
				k = 273;
				break;
			case 10:
				k = 304;
				break;
			case 11:
				k = 336;
				break;

		}



	if (r != 7)
		return r;
	if (r == 7)
		return r - 7;
	  
	
}



int planB(int y, int m, int d){
	if(m == 1 || m == 2){
		y--;
		m += 12; // 公式要求: 1 2月视为去年13 14月 
	}
	return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
}



int main(void){
	int i, j, k;
	for(i = 1900; i < 3000; i++){
		for(j = 1; j <= 12; j++){
			for(k = 1; k <= days[j] + isleap(i, j); k++){
				if(planA(i, j, k) != planB(i, j, k)){
					printf("%d.%d.%d: %d(True: %d)\n", i, j, k, planA(i, j, k), planB(i, j, k));
				}
			}
		}
	}
	return 0;
}
