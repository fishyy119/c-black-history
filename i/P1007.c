#include <stdio.h>

int main(void){ // ֻ�������ϵĵ㣬��ʿ��������ͷ����ʿ�������Է���Ч 
	int l, n, a, i;
	int min = 0, max = 0;
	scanf("%d%d", &l, &n); 
	for(i = 0; i < n; i++){
		scanf("%d", &a);
		if((a > l - a + 1 ? l - a + 1 : a) > min){
			min = (a > l - a + 1 ? l - a + 1 : a);
		}
		if((a > l - a + 1 ? a : l - a + 1) > max){
			max = (a > l - a + 1 ? a : l - a + 1);
		}
	}
	printf("%d %d\n", min, max);
	return 0;
}
