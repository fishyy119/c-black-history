#include <stdio.h>
#include <string.h>
// 另一个思路：统计012345679出现次数，依次输出即可 
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
