#include <stdio.h>
#include <string.h>

void reverse(char *x){ // ���� 
	int i;
	char tmp;
	for(i = 0; i < strlen(x) / 2; i++){
		tmp = x[i];
		x[i] = x[strlen(x) - i - 1];
		x[strlen(x) - i - 1] = tmp;
	}
}

void clearZero(char *x){ // ȥ��ǰ���� 
	int i = 0, j = 0;
	while(x[i] != '\0'){
		if(j == 0 && x[i] == '0'){ 
			continue;
		}
		x[j++] = x[i];
		i++;
	}
	x[j] = '\0';
}

int main(void){
	int i, j = 0, k = 0;
	char result[2000] = "";
	char num[2][1000] = {"", ""};
	char ch;
	for(i = 0; i < 2; i++){
		gets(num[i]);
		clearZero(num[i]);
	}
	reverse(num[0]);
	reverse(num[1]);
	for(i = 0; i < strlen(num[0]); i++){
		for(j = 0; j < strlen(num[1]); j++){
//			result[i + j] -= '0';
			result[i + j] += (num[0][i] - '0') * (num[1][j] - '0') + '0'; 
			k = 0;
			do{
			result[i + j + k+ 1] += result[i + j + k] / 10;
			result[i + j + k] %= 10;
			k++;
			}while(result[i + j + k + 1] / 10 == 0); // ��֤ÿλ���Ǹ�λ�� 
		}
	}
	reverse(result);
	clearZero(result); // ascii��0���ַ�0���ڻ��� !!!!
	for(i = 0; i < 10; i++){
		printf("%d ",result[i]);
	}
//	puts(num[0]);
//	puts(num[1]);
	return 0;
}
