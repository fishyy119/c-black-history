#include <stdio.h>

int main(void){
	int n,m,sum = 0;
	scanf("%d",&n);
	for(m = 1; ; m++){
		sum += m;
		if(sum >= n){
			break;
		}
	}
	printf("%d\n",m);
	return 0;
}
