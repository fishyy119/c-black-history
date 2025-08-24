  
int main(void){ 
	int year1, year2, month1, month2, day1, day2;
	int i, time= 0;
	scanf("%d%d%d", &year1, &month1, &day1);
	scanf("%d%d%d", &year2, &month2, &day2);
	for(i = 0; i < year2 - year1; i++){
		time += year_days(year1 + i);
	}
	printf("%d days\n", days(year2, month2, day2) - days(year1, month1, day1) + time);
	return 0; 
}  

