#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
	char str[5000] = "", strInt[5000] = "", strDec[5000] = "", strIndex[5000] = "";
	int i, j, numIndex, numInt, flagE = 0, flagPoint = 0;
	gets(str);
	
	j = 0;
	for(i = 0; i < strlen(str); i++){
		if(str[i] != ' '){
			strInt[j] = str[i];
			if(str[i] == '.'){
				flagPoint = 1;
				break;
			}
			else if(str[i] == 'e' || str[i] == 'E'){
				flagE = 1;
				break;
			}
			j++;
		}
	}  //  ����flag�����������  10��01 
	strInt[j] = '\0';
	
	j = 0;
	if(flagPoint == 1){
		for(i++; i < strlen(str); i++){
			if(str[i] != ' '){
				strDec[j] = str[i];
				if(str[i] == 'e' || str[i] == 'E'){
					flagE = 1;
					break;
				}
				j++;
			}
		}
	}
	strDec[j] = '\0';  //  ��ĩβ��e�滻Ϊ\0 
	
	j = 0;
	for(i++; i < strlen(str); i++){
		if(str[i] != ' '){
			strIndex[j] = str[i];
			j++;
		}
	} 
	strIndex[j] = '\0';
	numIndex = atoi(strIndex);  
	strcpy(str, strInt); // str������ʱ��������λ 
	
	for(i = strlen(strDec); i < 8 + numIndex; i++){  //  �ں�����ϸպ��㹻��0
		strDec[i] = '0';
	}
	strDec[i] = '\0'; 
	if(numIndex < 0){  //  ��ǰ����ϸպ��㹻��0 
		strInt[0] = '0';
		strInt[1] = '.';
		for(i = 2; i <= fabs(numIndex); i++){
			strInt[i] = '0';
		}
		strcat(strInt, str);
		strInt[i + 1] = '\0';
		if(fabs(numIndex) >= 8){ //���Ĵ� �������޷�ͨ�������壩 
			strInt[10] = '\0';
		}
	}
	else{
		for(i = 9 + numIndex; i > numIndex; i--){  //  ��С�������ַ�����һλ
			strDec[i] = strDec[i - 1]; 
		}
		strDec[i] = '.';
		strDec[numIndex + 9] = '\0';  //  ���ڽضϳ���8λ�Ĳ��� 
	}
	if(numIndex <= -8){ //���Ĵ� �������޷�ͨ�������壩 
		puts(strInt);
	}
	else{
		strcat(strInt, strDec);	
		puts(strInt);
	}

	return 0;
}
