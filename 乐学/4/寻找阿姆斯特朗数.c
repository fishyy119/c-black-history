#include <stdio.h>
#include <math.h>
#define N 8  /* �˴�NӦ��С�ڽ�Ҫ�����n */

int a[N], b[N], n, num;
int i, j, armstrong, temp = 0, dontHave = 0;

void C9n(int x){ // �ݹ� 
	if(x == 0){
		num = 0;
		for(i = 0; i < n; i++){  //  ��λ��n�η�֮�� 
			num += (int)pow(a[i], n);
		}
		if((num / (int)pow(10, n-1)) && !(num / (int)pow(10, n))){  //  num��nλ��? 
			for(i = 0; i < n; i++){  //  ȡnum��λ�� 
				b[i] = num % (int)pow(10, i + 1) / (int)pow(10, i);  // �������������pow�����Ż��ռ�ǳ��� 
			}
			for(i = n - 1; i > 0; i--){  //  ��b[0]~b[n-1]���� 
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
				if(a[i] != b[i]){  //  �Ƚϸ�λ���Ƿ���� 
					armstrong = 0;
				}
			}
			if(armstrong){  //  �ǰ�ķ˹������ 
				printf("%d\n",num);
				dontHave = 1;
			}
		}
		return;
	}
	else{
		for(a[x - 1] = 0; a[x - 1] <= a[x]; a[x - 1]++){  //  �������У�������һ���ѭ�� 
			C9n(x - 1);
		}
	}
}

int main(void){
	scanf("%d", &n);
	a[n] = 9;
	C9n(n);	
	if(!dontHave){  //  û���κ���� 
		printf("No output.\n");
	}
	return 0;  /* ��Ȼû�����Ᵽ֤���մ�С������,����n<=9ʱ���������Ҫ��,n>=10ʱû��������� */
}
