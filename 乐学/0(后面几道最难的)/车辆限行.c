#include <stdio.h>
#include <stdlib.h>

int daysPmonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeap(int y){
	if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
		return 1;
	}
	return 0;
}

int getWeek(int y, int m, int d){
	if(m == 1 || m == 2){
		y--;
		m += 12; // 公式要求: 1 2月视为去年13 14月 
	}
	return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 ) % 7;
} // Monday --> 0，Tuesday --> 1, ... , Sunday --> 6 

int getTime(int y, int m, int d){ // 计算输入日期与2012.4.9的距离 (日期必在2012.4.9后)
	int i, result = 0;
	result += (y - 2012) * 365 + (y - 2012) / 4 + (y - 2000) / 400 - (y - 2000) / 100; 
	for(i = 1; i < m; i++){
		result += daysPmonth[i];
	} // 计算yyyy.m.1到2012.1.1的距离(忽略2012.2.29) 
	if(m >= 3 && y > 2012){
		result += isLeap(y);
	}
	result += d;
	result -= 99;
	return result;
}

int main(void){
	int car[5][2] = {{3, 8}, {4, 9}, {5, 0}, {1, 6}, {2, 7}};
	int year, month, day;
	scanf("%d%d%d", &year, &month, &day);
	if(getWeek(year, month, day) >= 5){
		printf("Free.\n");
	}
	else{
		int index = ((5 - getTime(year, month, day) / 7 / 13 % 5) + getWeek(year, month, day)) % 5;
		printf("%d and %d.\n", car[index][0], car[index][1]); // 由星期和周数分别提供一个偏移量 
	}
	system("PAUSE");
	return 0;
}
