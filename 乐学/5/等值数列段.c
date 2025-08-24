#include <stdio.h>

int main(void){
	int n, i, j = 0, k = 0, a[50], b[50] = {0}; //  i用于for循环，j用于判断紧邻前两位是否连续，k用于表示这是第k段等值组，a[]用于输入，b[]用于记录每段始末位置 
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	for(i = 0; i < n - 1; i++){
		if(j == 0){
			if(i == n - 2){
				if(a[i] == a[i + 1]){
					b[2 * k] = i;
					b[2 * k + 1] = i + 1;
					k++;
				}
			}
			else{
				if(a[i] == a[i + 1]){
					j = 1;
					b[2 * k] = i;
				}
			}
		}
		else{
			if(i == n - 2){
				if(a[i] == a[i + 1]){
					b[2 * k + 1] = i + 1;
					k++;
				}
				else{
					b[2 * k + 1] = i;
					k++;
				}
			}
			else{
				if(a[i] != a[i + 1]){
					b[2 * k + 1] = i;
					j = 0;
					k++;
				}
			}
		}
	}
	if(k == 0){
		printf("No equal number list.\n");
	}
	else{
		n = 0;
		for(i = 0; i < 2 * k; i += 2){  //  j用于记录最长段的起始序号在b中的序号，n用于记录目前最大长度
			if(b[i + 1] - b[i] + 1 > n){
				n = b[i + 1] - b[i] + 1;
				j = i;
			}
		}
		printf("The longest equal number list is from %d to %d.\n", b[j], b[j + 1]);
	}
	return 0;
}
