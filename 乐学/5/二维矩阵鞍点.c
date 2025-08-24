#include <stdio.h>

int main(void){
	int i, j, tempNum, tempNo, n, m, a[50][50], c[50] = {0}, r[50] = {0};  // n行m列，a[行][列]为矩阵，c[]记录每列最小值的行数，r[]记录每行最大值的列数 
	scanf("%d%d",&n,&m);
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i = 0; i < n; i++){  // 求每行最大值的列数 
		tempNum = a[i][0];
		tempNo = 0;
		for(j = 1; j < m; j++){
			if(a[i][j] > tempNum){
				tempNum = a[i][j];
				tempNo = j;
			}
		}
		r[i] = tempNo;
	}
	for(j = 0; j < m; j++){  // 求每列最小值的行数
		tempNum = a[0][j];
		tempNo = 0;
		for(i = 1; i < n; i++){
			if(a[i][j] < tempNum){
				tempNum = a[i][j];
				tempNo = i;
			}
		} 
		c[j] = tempNo;
	}
	for(i = 0; i < n; i++){
		if(c[r[i]] == i){
			printf("Point:a[%d][%d]==%d\n",i,r[i],a[i][r[i]]);
			return 0;
		}
	}
	printf("No Point\n");
	return 0;
}
