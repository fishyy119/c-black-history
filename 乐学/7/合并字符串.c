#include <stdio.h>
#include <string.h>

int main(void){
	char a[10] = "", b[10] = "", c[20] = "";
	int i, j = 0, k = 0;  //  j指引b，k指引c 
	gets(a);
	gets(b);
	for(i = 0; i < strlen(a); i++){
		while(a[i] > b[j] && b[j] != 0){
			c[k] = b[j];
			j++;
			k++;
		}
		c[k] = a[i];
		k++;
	}
	for(; j < strlen(b); j++){
		c[k] = b[j];
		k++;
	}
	puts(c);
	return 0;
}
