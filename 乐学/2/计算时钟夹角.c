#include <stdio.h>
#include <math.h>

int main(void){
	int hour,minute;
	double hourA,minuteA;
	scanf("%d%d",&hour,&minute);
	minuteA = 360.0 * minute / 60;
	hourA= 360.0 * hour / 12 + 30.0 * minute / 60;
	hourA -= 360.0 * ((int)hourA / 360);
	printf("At %d:%02d the angle is %.1lf degrees.\n",hour,minute, -1 * fabs(fabs(minuteA - hourA) - 180.0) + 180.0); /* y=-||x|-180|+180 x¡Ê[-360,360] */
	return 0;
}
