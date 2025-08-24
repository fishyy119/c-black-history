#include <stdio.h>

int Fleap(int x){
	if(x % 4 == 0 && x % 100 != 0 || x % 400 == 0){
		return 1;  
	}
	else{
		return 0;
	}
}

int main(void){
	int year, month, day, n, i, leap = 0;  // leap表示跳几年 
	int dayPmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	scanf("%d%d%d", &year, &month, &day);
	scanf("%d",&n);
	
	while(n > 0){
		dayPmonth[1] = 28;
		dayPmonth[1] += Fleap(year + leap);
		for(i = 0; i < 12; i++){
			if(leap == 0){
				if(i < month - 1){
					continue;
				}
				else if(i == month - 1){
					if(n + day <= dayPmonth[i]){
						printf("%d.%d.%d\n", year, i + 1, day + n);
						return 0;
					}
					else{
						n -= dayPmonth[i] - day;
					}
				}
				else{
					if(n <= dayPmonth[i]){
						printf("%d.%d.%d\n",year, i + 1, n);
						return 0;
					}
					else{
						n -= dayPmonth[i];
					}
				}
			}
			else{
				if(n <= dayPmonth[i]){
					printf("%d.%d.%d\n",year + leap, i + 1, n);
					return 0;
				}
				else{
					n -= dayPmonth[i];
				}
			}
		}
		leap++;
	}	
	return 0;
}
