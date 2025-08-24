#include <stdio.h>

int main(void){ // ÀëÆ× 
	int a[10000][4], n, x, y;
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
		a[i][2] += a[i][0];
		a[i][3] += a[i][1];
	}
	scanf("%d%d", &x, &y);
	for(i = n - 1; i >= 0; i--){
		if(x >= a[i][0] && x <= a[i][2] && y >= a[i][1] && y <= a[i][3]){
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
