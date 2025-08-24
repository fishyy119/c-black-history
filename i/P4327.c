#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	char str[10000], frame[4] = {'*', '#', '#', '*'};
	int i, j;
	scanf("%s", str);
	
	for(i = 1; i <= 5; i++){
		if(i != 3){
			printf(".");
		}
		else{
			printf("#");
		}
		for(j = 1; j <= strlen(str); j++){
			if(i == 1 || i == 5){
				printf(".%c..", frame[j % 3]);
			}
			else if(i == 2 || i == 4){
				printf("%c.%c.", frame[j % 3], frame[j % 3]);
			}
			else{
				printf(".%c.%c", str[j - 1], frame[j % 3 + (j % 3 == 2 && j != strlen(str))]);
			}
		}
		printf("\n");
	}
	return 0;
}
