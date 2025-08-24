#include <stdio.h>
#include <string.h>

int main(void){
	char str[100] = "", op;
	int num[50] = {0}, temp, result, flag = 0, i, k, j = 0; // flag用于判断整数是否有多位 
	gets(str);
	for(i = 0; i < strlen(str); i++){
		if(str[i] >= '0' && str[i] <= '9'){
			if(flag == 0){
				num[j] = str[i] - '0';
				j++;
				flag = 1;
			}
			else if(flag == 1){
				j--;
				num[j] = num[j] * 10 + str[i] - '0';
				j++;
			}
		}
		else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%'){
			op = str[i];
			flag = 0;
		}
		else{
			flag = 0;
		}
	}
	j--;
	for(i = j; i > 0; i--){
		for(k = 0; k < i; k++){
			if(num[k] > num[k + 1]){
				temp = num[k];
				num[k] = num[k + 1];
				num[k + 1] = temp;
			}
		}
	}
	if((op == '/' || op == '%') && num[0] == 0){
		printf("Error!\n");
		return 0;
	}
	switch(op){
		case '+':result = num[j] + num[0];break;
		case '-':result = num[j] - num[0];break;
		case '*':result = num[j] * num[0];break;
		case '/':result = num[j] / num[0];break;
		case '%':result = num[j] % num[0];break;
	}
	printf("%d%c%d=%d\n",num[j], op, num[0], result);
	return 0;
}
