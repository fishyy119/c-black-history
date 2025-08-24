#include <stdio.h>  

int findf(int x){
	if(x >= 0 && x <= 4){
		return 1;
	}
	else if(x > 4 && x % 2 == 0){
		return findf(x - 1) + findf(x - 3);
	}
	else if(x > 4 && x % 2 == 1){
		return findf(x - 2) + findf(x - 4);
	}
	else{
		return -1;
	}
}
  
int main()  
{  int n,s, findf( int );  
   scanf("%d", &n);  
   s = findf(n);  
   printf("%d\n", s);  
   return 0;  
}  
