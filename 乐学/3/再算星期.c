#include <stdio.h>
// 太狗屎了，不要用 
int main(void){
	int year,month,day,time,leap;
	scanf("%d%d%d",&year,&month,&day);
	
	if((month >= 13) || (month <= 0)){
		printf("month is error.\n");
	}
	else if(((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) && (day > 31)){
		printf("day is error.\n");
	}
	else if(((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day >30)){
		printf("day is error.\n");
	}
	else {
		if((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))){
			leap = 1;  /*是闰年*/
		}
		else{
			leap = 0;
		}
		if((month == 2) && (day > 28 + leap)){
			printf("day is error.\n");
		}
		else{
				time = (year - 1900) * 365 + (year-1900) / 4 - (year - 2000) / 100 + (year - 2000) / 400;  /*time中提前加上了该年的2月29日*/	
				if(month == 1)
					time += day - leap;
				else if(month == 2)
					time += 31 + day - leap;
				else if(month == 3)
					time += 31 + 28 + day;
				else if(month == 4)
					time += 31 + 28 + 31 + day;
				else if(month == 5)
					time += 31 + 28 + 31 + 30 + day;
				else if(month == 6)
					time += 31 + 28 + 31 + 30 + 31 + day;
				else if(month == 7)
					time += 31 + 28 + 31 + 30 + 31 + 30 + day;
				else if(month == 8)
					time += 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;
				else if(month == 9)
					time += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
				else if(month == 10)
					time += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
				else if(month == 11)
					time += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
				else if(month == 12)
					time += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
				printf("%d\n",time % 7);
		}
	}
	return 0;
}
