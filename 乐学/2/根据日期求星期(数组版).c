#include <stdio.h>

int main(void){
	int dayPmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i, year, month, day, time, leap = 0;
	scanf("%d%d%d",&year,&month,&day);
	
	time = (year - 1900) * 365 + (year-1900) / 4 - (year - 2000) / 400;  /*time中提前加上了该年的2月29日*/
	if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
		leap = 1;  /*是闰年*/	
	}
	for(i = 0; i < month - 1; i++){
		time += dayPmonth[i];
	}	
	time += day;
	if(leap && month <= 2){
		time -= leap;
	}
	printf("%d\n",time % 7);
	return 0;
}
