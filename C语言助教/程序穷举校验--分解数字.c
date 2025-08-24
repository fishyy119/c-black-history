#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int F(int x,int y){
	int i=1,m=0,a=0,b=0;
	a=(x-2*y)>=0?y:x-y;
	if(x>1&&y<x){
		for(i=1;i<=a;i++){
		m+=F(x-y,i);
		}
		return m;
	}
	else{
		return 1;
	}
}

int planA(int m, int n){
	int i=0,x=0;
	
	for(i=1;i<=n;i++){
		x+=F(m,i);
	}
	return x;

}

// -------------------------------------------------------
int f(int m, int n){
	int i, result = 0;
	if(n > m){
		n = m;
	}
	if(n <= 1){
		result = 1;
	}
	else{
		for(i = 2; i <= n; i++){
			result += f(m - i, i);
		}
		result++;
	}
	return result;
}


int planB(int m, int n){

	return f(m, n);
	
}
// -------------------------------------------------------


int main(void){
	int i, j;
	for(i = 1; i < 10; i++){
		for(j = 1; j < 10; j++){
			if(planA(i, j) != planB(i , j)){
				printf("%d.%d:%d(true:%d)\n",i,j,planA(i,j), planB(i,j));
			}
		}
	}
	return 0;
}
