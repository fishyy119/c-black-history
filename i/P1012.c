#include <stdio.h>
#include <string.h>

int min(int x, int y){
	return (x > y ? y : x);
}

int main(void){
	int i, j, k = 0, n;
	int m, flag = 1; // m��¼��ǰmax, flag��¼ǰminλ�Ƿ���ȫ��� 
	char a[20][10], max[10];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%s", a[i]);
	}
	for(i = 0; i < n; i++){
		flag = 1;
		for(j = 0; j < n; j++){
			if(a[j][0] != '\0'){
				m = j;
				break; // �ҵ���һ���������������������max 
			}
		}
		for(j++; j < n; j++){
			if(a[j][0] == '\0'){
				continue;
			}
			for(k = 0; k < min(strlen(a[m]), strlen(a[j])); k++){
				if(a[m][k] < a[j][k]){
					flag = 0
					m = j;
					break;
				}
				else if(a[m][k] == a[j][k]){
					continue;
				}
				else{
					flag = 0
					break;
				}
			}
			if(flag){
				
			}
		}
		printf("%s", a[m]);
		a[m][0] = '\0';
		
	}
	return 0;
}
