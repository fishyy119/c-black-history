#include <stdio.h>

int week(int year, int month, int day){
	int dayPmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int time, leap = 0, i;
	
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
	return time % 7;
}

int main(void){
	int yearInput, j, k = 0, result[12] = {0};
	scanf("%d",&yearInput);
	for(j = 1; j <= 12; j++){
		if(week(yearInput, j, 13) == 5){
			result[k] = j;
			k++;
		}
	}
	if(k == 0){
		printf("There is %d Black Friday in year %d.\n", k, yearInput);
	}
	
	if(k != 0){
		if(k == 1){
			printf("There is %d Black Friday in year %d.\n", k, yearInput);
			printf("It is:\n");
		}
		else{
			printf("There are %d Black Fridays in year %d.\n", k, yearInput);
			printf("They are:\n");
		}
		for(j = 0; j < k; j++){
			printf("%d/%d/13\n", yearInput, result[j]);
		}
	}
	return 0;
}
