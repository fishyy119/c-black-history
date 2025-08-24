#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
void reverse();

int main( ){   
	char str[100];  
    int start, end;  
    gets(str);  
    scanf("%d%d", &start, &end);  
    reverse( str, start, end );  
    printf("%s\n", str);  
    return 0;  
}  

void reverse(char str[], int start, int end){
	char temp;
	if(end > strlen(str) - 1){
		end = strlen(str) - 1;
	}
	if(start < end){
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		reverse(str, start + 1, end - 1);
	}
}  
