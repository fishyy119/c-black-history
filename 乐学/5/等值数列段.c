#include <stdio.h>

int main(void){
	int n, i, j = 0, k = 0, a[50], b[50] = {0}; //  i����forѭ����j�����жϽ���ǰ��λ�Ƿ�������k���ڱ�ʾ���ǵ�k�ε�ֵ�飬a[]�������룬b[]���ڼ�¼ÿ��ʼĩλ�� 
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
		for(i = 0; i < 2 * k; i += 2){  //  j���ڼ�¼��ε���ʼ�����b�е���ţ�n���ڼ�¼Ŀǰ��󳤶�
			if(b[i + 1] - b[i] + 1 > n){
				n = b[i + 1] - b[i] + 1;
				j = i;
			}
		}
		printf("The longest equal number list is from %d to %d.\n", b[j], b[j + 1]);
	}
	return 0;
}
