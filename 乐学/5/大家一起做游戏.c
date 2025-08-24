#include <stdio.h>

int main(void){
	int m,n,i,a = 0,b[50]={0},say = 1; //b记录被淘汰者 a记录被淘汰者数 
	scanf("%d%d",&n,&m);
	while(1){		
		while(say <= m){
			say += n - a;
		}
		say -= n - a;		
		for(i = 0; i < n ; i++){
			if(b[i] == 1){
				continue;
			}
			if(say == m){
				b[i] = 1;
				a += 1;
				say = 0;
			}
			say += 1;
		}
		if(n - a == 1){
			break;
		}
	}
	for(i = 0; i < n; i++){
		if(b[i] == 0){
			printf("The left child is NO %d.\n",i + 1);
		}
	}
	return 0;
}
