#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dictionary{
	char str[50];
	int numble;
};

int main(void){
	struct dictionary dictionary[10000];
	char ch, outPut[50] = "";
	int i = 0, j = 0, k; // iָ��outPut��j��ʾ���������ݵ�dictionary��� 
	while((ch = getchar()) != EOF){
		if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z'){
			outPut[i] = ch;
			i++;
		}
		else{ // һ�����ʽ��� 
			if(outPut[0] != '\0'){ // outPut��δ��� 
				outPut[i] = '\0'; // ��outPutĩ�˼ӽ����� 
				for(k = 0; k < j; k++){   // �˴������ֵ� 
					if(strcmp(dictionary[k].str, outPut) == 0){
						break; 
					}
				}
				if(k == j){ // ���ֵ���δ�ҵ��������ֵ䣬���outPut 
					strcpy(dictionary[j].str, outPut);
					dictionary[j].numble = j + 1;
					j++;
					printf("%s", outPut);
					outPut[0] = '\0';
				}
				else{ // ���ֵ��д��ڣ������Ӧnumble 
					printf("%d", dictionary[k].numble);
					outPut[0] = '\0';
				}
			}
			putchar(ch); // ԭ���������ĸ�ַ� 
			i = 0;
		}
	}
	return 0;
}
