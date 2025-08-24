#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

int isleap(int y, int m){
	if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
		if(m == 2){
			return 1;
		}
	}
	return 0;
}




int planA(int y1, int m1, int d1, int y2, int m2, int d2){
	
int p=0,q=0,d=0,m3=0,m[12]={31,29,31,30,31,30,31,31,30,31,30,31};
//	scanf("%d %d %d",&y1,&m1,&d1);
//	scanf("%d %d %d",&y2,&m2,&d2);
	if(y1%4!=0||y1%100==0&&y1%400!=0){//判断是否是闰年 
		p=1,m[1]=28;
	}
	if(y2%4!=0||y2%100==0&&y2%400!=0){
		q=1;
	}
	if(p==0&&q!=0&&m1<=2||q==0&&p!=0&&m2>2){//有一年是闰年另一个不是结果加1 
		d=d+1;
	}
	while(m1<m2){//月份的计算 
		m3+=m[m1-1];
		m1++;
	}
	while(m1>m2){
		m3-=m[m2-1];
		m2++;
	}
	d=d+(y2-y1)*365+(y2-y1)/4-(y2-y1)/100+(y2-y1)/400+m3+d2-d1;//最终的计算 
//	if(d>1){
//		printf("%d days\n",d);
//	}
//	if(d==1){
//		printf("1 day\n");
//	}
//	return 0;
	return d;
}



int planB(int year1, int month1, int day1, int year2, int month2, int day2){
	int dayPmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int time1, leap1, i;
	int time2, leap2;
//	scanf("%d%d%d", &year1, &month1, &day1);
//	scanf("%d%d%d", &year2, &month2, &day2);
	
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
	
	return time2 - time1;
	
}



int main(void){
	int i1, j1, k1, i2, j2, k2;
	for(i1 = 2001; i1 < 2300; i1++){
		for(j1 = 1; j1 <= 12; j1++){
			for(k1 = 1; k1 <= days[j1] + isleap(i1, j1); k1++){
				for(i2 = i1; i2 <= i1 + 5; i2++){
					for(j2 = (i2 == i1 ? j1 : 1); j2 <= 12; j2++){
						for(k2 = (i2 == i1 && j2 == j1 ? k1 : 1); k2 <= days[j2] + isleap(i2, j2); k2++){
							int A = planA(i1, j1, k1, i2, j2, k2);
							int B = planB(i1, j1, k1, i2, j2, k2);
							if(A != B){
								printf("%d.%d.%d--%d.%d.%d: %d(True: %d)\n", i1, j1, k1, i2, j2, k2, A, B);
							}
						}
					}
				}
				
			}
		}
	}
	return 0;
}
