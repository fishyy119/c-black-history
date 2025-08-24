#include <stdio.h>

int main(void){
	int n, a[9][100] = {0}, i, j, l, k;  //  a[x][0]存储a[x]的有效数字个数, a[x]对应x + 1位数, i j l用于循环, k用于计数 
	scanf("%d",&n);
	a[0][0] = 9;  //  一位数对应情况易得 
	for(i = 1; i < 10; i++){
		a[0][i] = i;
	}
	if(n == 0){
		printf("0\n");
	}
	else{
		for(i = 0; i < n - 1; i++){  //  数字位数从1到n递推 
			k = 0;
			for(j = 1; j <= a[i][0]; j++){  //  在a[i]每个数后依次加0 ~ 9 
				for(l = 0; l < 10; l++){
					if((a[i][j] * 10 + l) % ((i + 2) * (i + 2)) == 0){
						k++;
						a[i + 1][k] = a[i][j] * 10 + l;
					}
				}
			}
			a[i + 1][0] = k;
		}
		printf("%d\n",a[n - 1][0]);
	}	
	return 0;
}
