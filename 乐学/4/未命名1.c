#include <stdio.h>
#include <math.h>

		
		
int main(void){
	int a[6], b[6], n, num;
	int i, j, armstrong, temp = 0;
	scanf("%d", &n);
	a[n] = 9;
	
	for(a[n-1] = 0; a[n-1] <= a[n]; a[n-1]++){
		for(a[n-2] = 0; a[n-2] <= a[n-1]; a[n - 2]++){
			for(a[n-3] = 0; a[n-3] <= a[n-2]; a[n - 3]++){
			num = 0;
	//	printf("%d %d %d\n",a[0],a[1],a[2]);
		for(i = 0; i < n; i++){  // 各位数n次方之和 
			num += (int)pow(a[i], n);
		}
		num = 407;
		if(((num / (int)pow(10, n - 1)) != 0) && ((num / (int)pow(10, n)) == 0)){  // num是n位数 
			printf("yes");
			for(i = 0; i > n; i++){  // 取num各位数 
				b[i] = num % (int)pow(10, i + 1) / (int)pow(10, i);
			}
			for(i = n - 1; i < 0; i--){  // 对b[0]~b[n-1]排序 
				for(j = 0; j < i; j++){
					if(b[j] > b[j + 1]){
						temp = b[j];
						b[j] = b[j + 1];
						b[j + 1] = temp;
					}
				}
				printf("%d,%d,%d",b[0],b[1],b[2]);
			}
			

			
			armstrong = 1;
			for(i = 0; i < n; i++){
				if(a[i] != b[i]){  //  比较各位数是否相等 
					armstrong = 0;
				}
			}
			if(armstrong){
				printf("%d",num);
			}
		}
	//	printf("%d\n",num);
	}
	}
	}
	return 0;
}		
	
	
		
		
