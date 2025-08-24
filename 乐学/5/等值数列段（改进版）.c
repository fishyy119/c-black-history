#include <stdio.h> 
/**************************************
对第一次提交通过的代码进行适当优化 
对第二次提交未通过的代码进行修正(最末端数字的处理) 
***************************************/
int main(void){ 
	int n, i, j = 1, a[50];  
	scanf("%d",&n); 
	for(i = 0; i < n; i++){ 
		scanf("%d",&a[i]); 
	} 
	for(i = 0; i < n - 1; i++){ // 将数列转化为多段公差为1、首项为1的等差数列的组合，每个数字x代表是这个等值数列段的第x位 
		if(a[i] == a[i + 1]){
			a[i] = j;
			j++;
		}
		else{
			a[i] = j;
			j = 1;
		}
	}
	if(j != 1){// 处理最末端的数字 
		a[n - 1] = a[n - 2] + 1;
	}
	else{
		a[n - 1] = 1;
	}
	int start = 0, startTmp = 0, max = 1;
	for(i = 0; i < n; i++){
		if(a[i] == 1){
			startTmp = i;
		}
		else if(a[i] > max){
			max = a[i];
			start = startTmp;
		}
	}
	if(max == 1){
		printf("No equal number list.\n");
	}
	else{
		printf("The longest equal number list is from %d to %d.\n", start, start + max - 1);
	}
	system("PAUSE");
  	return 0; 
}  
