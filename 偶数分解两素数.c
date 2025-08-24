#include <stdio.h>

int main(void){
	int n, a = 2, flag, i;
	scanf("%d", &n);
	for( ; a <= n - a; a++){
		flag = 1;
		for(i = 2; i < a || i < n - a; i++){
			if(a % i == 0 || (n - a) % i == 0){
				if(!(i == a && (n - a) % i != 0)){
					flag = 0;
					break;
				}
			}
		}
		if(flag){
			printf("%d+%d=%d\n", a, n - a, n);
		}
	}
	return 0;
}
