#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int n, i, m = 0;
	char num[1001];
	scanf("%d %s", &n, num);
	for(i = 0; i < strlen(num); i++){
		if(num[i] != '0'){
			m++; // 记录非零位个数 
		}
	}
	for(i = strlen(num); i > 0; i--){
		if(num[strlen(num) - i] == '0'){
			continue;
		}
		else{
			printf("%c*%d^%d", num[strlen(num) - i], n, i - 1);
			m--;
		}
		if(m == 0){
			printf("\n");
			break;
		}
		else{
			printf("+");
		}
	}
	system("PAUSE");
	return 0;
}
