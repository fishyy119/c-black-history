#include <stdio.h>
#include <math.h>
#define N 8  /* 此处N应不小于将要输入的n */

int a[N], b[N], n, num;
int i, j, armstrong, temp = 0, dontHave = 0;

void C9n(int x){ // 递归 
	if(x == 0){
		num = 0;
		for(i = 0; i < n; i++){  //  各位数n次方之和 
			num += (int)pow(a[i], n);
		}
		if((num / (int)pow(10, n-1)) && !(num / (int)pow(10, n))){  //  num是n位数? 
			for(i = 0; i < n; i++){  //  取num各位数 
				b[i] = num % (int)pow(10, i + 1) / (int)pow(10, i);  // 理论上来讲这个pow函数优化空间非常大 
			}
			for(i = n - 1; i > 0; i--){  //  对b[0]~b[n-1]排序 
				for(j = 0; j < i; j++){
					if(b[j] > b[j + 1]){
						temp = b[j];
						b[j] = b[j + 1];
						b[j + 1] = temp;
					}
				}
			}
			armstrong = 1;
			for(i = 0; i < n; i++){
				if(a[i] != b[i]){  //  比较各位数是否相等 
					armstrong = 0;
				}
			}
			if(armstrong){  //  是阿姆斯特朗数 
				printf("%d\n",num);
				dontHave = 1;
			}
		}
		return;
	}
	else{
		for(a[x - 1] = 0; a[x - 1] <= a[x]; a[x - 1]++){  //  升序排列，减少了一半的循环 
			C9n(x - 1);
		}
	}
}

int main(void){
	scanf("%d", &n);
	a[n] = 9;
	C9n(n);	
	if(!dontHave){  //  没有任何输出 
		printf("No output.\n");
	}
	return 0;  /* 虽然没有特意保证按照大小输出结果,但在n<=9时输出均符合要求,n>=10时没有输出数据 */
}
