#include <stdio.h> 
/**************************************
�Ե�һ���ύͨ���Ĵ�������ʵ��Ż� 
�Եڶ����ύδͨ���Ĵ����������(��ĩ�����ֵĴ���) 
***************************************/
int main(void){ 
	int n, i, j = 1, a[50];  
	scanf("%d",&n); 
	for(i = 0; i < n; i++){ 
		scanf("%d",&a[i]); 
	} 
	for(i = 0; i < n - 1; i++){ // ������ת��Ϊ��ι���Ϊ1������Ϊ1�ĵȲ����е���ϣ�ÿ������x�����������ֵ���жεĵ�xλ 
		if(a[i] == a[i + 1]){
			a[i] = j;
			j++;
		}
		else{
			a[i] = j;
			j = 1;
		}
	}
	if(j != 1){// ������ĩ�˵����� 
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
