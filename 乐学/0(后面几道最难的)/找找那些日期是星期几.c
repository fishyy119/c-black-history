
#include <stdio.h>

int daysPmonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30 ,31};

int getWeek(int y, int m, int d){
	if (m == 1 || m == 2){
		m +=12;
		y--;
	}
	return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
}

int isTrueDate(int y, int m, int d){
	if(y == 2017 || y == 2018){
		if(m >= 1 && m <= 12){
			if(daysPmonth[m] >= d){
				return 1;
			}
		}
	}
	return 0;
}

int main(void){
	int year, month, day;
	int i, j, k, week, m = 1;
	scanf("%d-%d-%d", &year, &month, &day);
	scanf("%d", &week);
	printf("[2017-01-01~%d-%02d-%02d,%d]\n", year, month, day, week);
	if(!isTrueDate(year, month, day)){
		printf("ERROR!\n");
		return 0;
	}
	else{
		for(i = 2017; i <= 2018; i++){
			for(j = 1; j <= 12; j++){
				for(k = 1; k <= daysPmonth[j]; k++){
					if(i == year && j == month && k == day){
						if(m == 1){
							printf("NO DATE FOUND!\n");
						}		
						return 0;
					}
					if(getWeek(i, j, k) == week){
						printf("%03d %d-%02d-%02d\n", m, i, j, k);
						m++;
					}
				}
			}
		}
	}
	
	return 0;
}
