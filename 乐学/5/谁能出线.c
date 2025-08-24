#include <stdio.h>

int main(void){
	int a[10],i,j,temp,b[10] = {1,2,3,4,5,6,7,8,9,10};
	for(i = 0; i < 10; i++){
		scanf("%d",&a[i]);
	}
	for(i = 9; i > 0; i--){
		for(j = 0; j < i; j++){
			if(a[j] > a[j + 1]){
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
		}
	}
	j = 1;
	for(i = 9; i > 0; i--){
		if(a[i] == a[i - 1]){
			j += 1;
		}
		else{
			break;
		}
	}
	for(; j > 0; j--){
		printf("%d\n",b[9 - j + 1]);
	}	
	return 0;
}
