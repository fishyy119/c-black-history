#include <stdio.h>

int main(void){
	int a[20], n, i, j;
	scanf("%d",&n);
	for(j = n - 1; j >= 0; j--){
		scanf("%d",&a[j]);
	}
	for(i = 0; i < n / 2; i++){
		printf("%d ",a[i] * a[n - i - 1]);
	}
	if(n % 2){
		printf("%d \n",a[n / 2]);
	}
	else{
		printf("\n");
	}
	return 0;
}
