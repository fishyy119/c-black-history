#include <stdio.h>

int main(void){
	int h, l, time;
	scanf("%d*%d%d",&h,&l,&time);
	printf("%d\n",(int)(h * l / 1024.0 * 3 * 30 * 60 * time));
	return 0;
}
