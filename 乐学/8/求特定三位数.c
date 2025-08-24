#include <stdio.h>

char str[4];

int getNum(int a, int b, int c){
	return a * 100 + b * 10 + c;
}

char* cutNum(int a){
	sprintf(str, "%d%d%d", a / 100 % 10, a / 10 % 10, a % 10);
	return str;
}

int main(void){
	int i, j, k, flag, n, num[10] = {0};
	int havePrintf = 0;
	scanf("%d",&n);
	num[n] = 1;
	for(i = 1; i < 10; i++){
		flag = 0;
		num[n] = 1;
		if(num[i] == 1){
			continue;
		}
		num[i] = 1;
		for(j = 1; j < 10; j++){
			flag = 0;
			num[i] = 1;
			num[n] = 1;
			if(num[j] == 1){
				continue;
			}
			num[j] = 1;
			int firstNum = getNum(n, i, j);
			for(k = 0; k < 3; k++){
				num[*(cutNum(firstNum * 2) + k) - '0']++;
				num[*(cutNum(firstNum * 3) + k) - '0']++;
			}
			for(k = 1; k < 10; k++){
				if(num[k] != 1){
					flag = 1; 
				}
			}
			if(flag == 0){
				printf("%d,%d,%d\n", firstNum, firstNum * 2, firstNum * 3);
				havePrintf = 1;
			}
			for(k = 0; k < 10; k++){
				num[k] = 0;
			}
		}
	}
	if(havePrintf == 0){
		printf("0,0,0\n");
	}
	
	return 0;
}
