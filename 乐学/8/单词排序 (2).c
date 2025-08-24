#include <stdio.h>
#include <string.h>

int main(void){
	char a[6][50];
	int i, j, k;
	for(i = 0; i < 5; i++){
		gets(a[i]);
		strcpy(a[i + 1], a[i]);
		for(j = 0; j < i; j++){
			if(strcmp(a[i], a[j]) > 0){
				for(k = i; k > j; k--){
					strcpy(a[k], a[k - 1]);
				}
				strcpy(a[j], a[i + 1]);
			}
		}
	}
	for(i = 0; i < 5; i++){
		puts(a[i]);
	}
	return 0;
}
