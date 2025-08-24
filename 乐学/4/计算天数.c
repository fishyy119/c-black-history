#include <stdio.h>
 
int main(void){
	int dayPmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year1, month1, day1, time1, leap1, i;
	int year2, month2, day2, time2, leap2;
	
	scanf("%d%d%d", &year1, &month1, &day1);
	scanf("%d%d%d", &year2, &month2, &day2);
	
	time1 = (year1 - 1900) * 365 + (year1-1900) / 4 - (year1 - 2000) / 100 + (year1 - 2000) / 400;  /*time中提前加上了该年的2月29日*/
	if(year1 % 4 == 0 && (year1 % 100 != 0 || year1 % 400 == 0))
		leap1 = 1;  /*是闰年*/
	else
		leap1 = 0;
			
	time2 = (year2 - 1900) * 365 + (year2 - 1900) / 4 - (year2 - 2000) / 100 + (year2 - 2000) / 400;  /*time中提前加上了该年的2月29日*/
	if(year2 % 4 == 0 && (year2 % 100 != 0 || year2 % 400 == 0))
		leap2 = 1;  /*是闰年*/
	else
		leap2 = 0;
	time1 += day1;
	time2 += day2;
	
	for(i = 0; i < month1 - 1; i++){
		time1 += dayPmonth[i];
	}	
	for(i = 0; i < month2 - 1; i++){
		time2 += dayPmonth[i];
	}
	
	if(leap1 && month1 <= 2){
		time1 -= leap1;
	}
	if(leap2 && month2 <= 2){
		time2 -= leap2;
	}
	
	printf("%d days\n",time2 - time1);
	return 0;
}
