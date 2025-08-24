#include <stdio.h>

int main(void){
	int year,time,leap,day = 1;
	scanf("%d",&year);
	time = (year - 1900) * 365 + (year-1900) / 4 - (year - 2000) / 100 + (year - 2000) / 400;
	if((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
		leap = 1;  /*ÊÇÈòÄê*/
	else
		leap = 0;
		
	time += 31 + 28 + 31 + 30 + day;   /* 1900-1-1 ~ year-5-1 */
	while(time % 7 != 0){
		time++;
		day++;
	}
	do{
		time++;
		day++;
	}while(time % 7 != 0);                                                                                                                                                                  
	printf("%d\n",day);
	return 0;
}
