#include <stdio.h>

int main(void){
	int n, m, i, j, temp;
	int a[1000] = {0}, b[1000] = {0};
	scanf("%d%d",&n,&m);
	for(i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	for(i = 0; i < m; i++){
		scanf("%d",&b[i]);
	}
	if(n > m){
		printf("bit is doomed!\n");
	}
	else{
		for(i = n - 1; i > 0; i--){
			for(j = 0; j < i; j++){
				if(a[j] > a[j + 1]){
					temp = a[j + 1];
					a[j + 1] = a [j];
					a[j] = temp;
				}
			}
		}
		for(i = m - 1; i > 0; i--){
			for(j = 0; j < i; j++){
				if(b[j] > b[j + 1]){
					temp = b[j + 1];
					b[j + 1] = b[j];
					b[j] = temp;
				}
			}
		}
		
/*		for(i = 0; i < n; i++){
			printf("%d ",a[i]);
		}
		for(i = 0; i < m; i++){
			printf("%d ",b[i]);
		}		*/
		j = 0;
		temp = 0;  //j用来储存所需学分 temp用来储存跳过的学生数 
		for(i = 0; i < n; i++){
			
			while(a[i] > b[i + temp]){
				temp++;
				if(m - temp < n){
					printf("bit is doomed!\n");
					return 0;
				}
			}
			j += b[i + temp];
		}
		printf("%d\n",j);
	}
	return 0;
}
