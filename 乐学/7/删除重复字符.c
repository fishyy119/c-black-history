#include <stdio.h>
#include <string.h>

int main(void){
	char a[101] = "";
	int i, j = 0;
	gets(a);
	for(i = 0; i < strlen(a); i++){
		if(strchr(a, a[i]) == &a[i]){
			a[j] = a[i];
			j++;
		}
	}
	a[j] = '\0';
	puts(a);
	return 0;
}
