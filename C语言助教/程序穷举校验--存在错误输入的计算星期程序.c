#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

int isleap(int y, int m) {
	if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
		if(m == 2) {
			return 1;
		}
	}
	return 0;
}

int planA(int year, int month, int date) {

	int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	if(year%4==0&&year%100!=0||year%400==0) {
		a[1]=29;
	}
	if(year<1900) {
		printf("year is error.\n");
		return 0;
	}
	if (month>12||month<1) {
	
		return 10;
	}
	if (date<1||date>a[month-1]) {

		return 20;
	}
	int y,m,d,w,c=0;
	if(month==1||month==2) {
		c=(year-1)/100;
		y=(year-1)%100;
		m=month+12;
		d=date;
	} else {
		c=year/100;
		y=year%100;
		m=month;
		d=date;
	}
	w=(d+1+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	if(w>=0) {
		w=w%7;
	} else {
		w=(w%7)+7;
	}
	return w;



}



int planB(int year, int month, int day) {
	int leap;
	if((month >= 13) || (month <= 0)) {
		return 10;// month is error
	} else if(((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) && (day > 31)) {
		return 20;// day is error
	} else if(((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day >30)) {
		return 20;// day is error
	} else if(day <= 0){
		return 20;
	}
	else {
		if((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) {
			leap = 1;  /*是闰年*/
		} else {
			leap = 0;
		}
		if((month == 2) && (day > 28 + leap)) {
			return 20;// day is error
		} else {
			if(month == 1 || month == 2) {
				year--;
				month += 12; // 公式要求: 1 2月视为去年13 14月
			}
			return (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
		}
	}
}



int main(void) {

	int i, j, k;
	for(i = 1900; i < 2000; i++) {
		for(j = 0; j <= 50; j++) {
			for(k = 0; k <= 100; k++) {
				if(planA(i, j, k) != planB(i, j, k)) {
					printf("%d.%d.%d: %d(True: %d)\n", i, j, k, planA(i, j, k), planB(i, j, k));
				}
			}
		}
	}
	return 0;
}
