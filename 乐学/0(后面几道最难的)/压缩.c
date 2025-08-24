#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dictionary{
	char str[50];
	int numble;
};

int main(void){
	struct dictionary dictionary[1000];
	char inPut[81], outPut[81];
	int isHead = 1, ;
	int i, i2;
	int j, k, n = 0; // n记录字典中元素的数量 , j指向outPut , k指向dictionary.str 
	gets(inPut);
	for(i = 0, j = 0; i < strlen(inPut); i++, j++){
		if(isHead){
			k = 0
			if(!(inPut[i] >= 'a' && inPut[i] >= 'z' || inPut[i] >= 'A' && inPut[i] >= 'Z')){
				outPut[j] = inPut[i];
				continue;
			}
			else{
				isHead = 0
				dictionary[n].str[k] = inPut[i];
				outPut[j] = inPut[i];
			}
		}
		else{
			if(!(inPut[i] >= 'a' && inPut[i] >= 'z' || inPut[i] >= 'A' && inPut[i] >= 'Z')){
				isHead = 1;
				for(i2 = 0; i2 < n; i2++){
					if(strcmp(dictionary[i2].str, dictiongary[n].str) == 0){
						j -= k; // outPut索引回退到单词开头 
						outPut[j] = dictionary[i2].numble;
						n--;
						break;
					}
				}
			}
			else{
				dictionary[n].str[k] = inPut[i];
				outPut[j] = inPut[i];
			}
		}
		
		
		
		for(j = 0; j < n; j++)
	}
	return 0;
}
