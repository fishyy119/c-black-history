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
	int i = 0, j = 0, k; // i指向outPut，j表示待存入数据的dictionary序号 
	while((ch = getchar()) != EOF){
		if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z'){
			outPut[i] = ch;
			i++;
		}
		else{ // 一个单词结束 
			if(outPut[0] != '\0'){ // outPut还未输出 
				outPut[i] = '\0'; // 在outPut末端加结束符 
				for(k = 0; k < j; k++){   // 此处查找字典 
					if(strcmp(dictionary[k].str, outPut) == 0){
						break; 
					}
				}
				if(k == j){ // 在字典中未找到，存入字典，输出outPut 
					strcpy(dictionary[j].str, outPut);
					dictionary[j].numble = j + 1;
					j++;
					printf("%s", outPut);
					outPut[0] = '\0';
				}
				else{ // 在字典中存在，输出对应numble 
					printf("%d", dictionary[k].numble);
					outPut[0] = '\0';
				}
			}
			putchar(ch); // 原样输出非字母字符 
			i = 0;
		}
	}
	return 0;
}
