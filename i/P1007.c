#include <stdio.h>

int main(void){ // 只看数轴上的点，两士兵相遇掉头与两士兵穿过对方等效 
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
