#include <stdio.h>
#include <string.h>
// ��һ��˼·��ͳ��012345679���ִ���������������� 
int main(void){
	char a[10000] = "", temp;
	int i, j;
	gets(a);
	for(i = 0; i < strlen(a); i++){
		for(j = strlen(a) - 1; j > i; j--){
			if(a[j] > a[j - 1]){
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
	puts(a);
	return 0;
}
