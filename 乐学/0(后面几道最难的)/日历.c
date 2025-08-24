#include <stdio.h>
#include <stdlib.h> 

int getWeek(int y, int m, int d){
	if(m == 1 || m == 2){
		y--;
		m += 12; // ��ʽҪ��: 1 2����Ϊȥ��13 14�� 
	}
	return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
} // Monday --> 0��Tuesday --> 1, ... , Sunday --> 6 

int maxDayPerMonth(int y, int m){ // ÿ��������� 
	int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(m == 2){
		if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
			return 1 + a[m - 1];
		}
	}
	return a[m - 1];
}

int isTrueDate(int y, int m, int d){
	if(y <= 3000 && y >= 1000){ // ������� 
		if(m <= 12 && m >= 1){ // �·����� 
			if(d <= maxDayPerMonth(y, m) && d >= 1){ // �������� 
				return 1;
			}
		}
	}
	return 0;
}

int main(void){
	char date[11] = "          "; // ��10���ո� 
	int year, day, month;
	int h, j, k;
	int weekTmp = 0;
	int i[3], weekOfFirstDay[3];
	scanf("%d-%d-%d", &year, &month, &day);
	
	if(isTrueDate(year, month, day)){ // ���������ںϷ�ʱ 
		sprintf(date, "%d-%02d-%02d", year, month, day); // ����yyyy-mm-dd,����Ϊ10 
		printf("+-----------------------------------------------------------------------------------------+\n");
		printf("|                                                                                         |\n");
		printf("|                               Calendar of Year [%2d%2d%2d%2d ]                              |\n", year / 1000, year / 100 % 10, year / 10 % 10, year % 10);
		printf("|                                                                                         |\n");
		
		for(h = 0; h < 4; h++){ // ��������Ϊ4�� 
			printf("+-----------------------------+-----------------------------+-----------------------------+\n");
			switch(h){ // ���ݿ�����, �������е��·���Ϣ 
				case 0:	printf("|             Jan             |             Feb             |             Mar             |\n");
						break;
				case 1: printf("|             Apr             |             May             |             Jun             |\n");
						break;
				case 2: printf("|             Jul             |             Aug             |             Sep             |\n");
						break;
				case 3:	printf("|             Oct             |             Nov             |             Dec             |\n");
						break;
			}
			printf("+-----------------------------+-----------------------------+-----------------------------+\n");
			printf("| Mon Tue Wed Thu Fri Sat Sun | Mon Tue Wed Thu Fri Sat Sun | Mon Tue Wed Thu Fri Sat Sun |\n");
			
			for(j = 0; j < 3; j++){ // ÿ�����������Ҫ�������, ���ó���Ϊ3������ֱ𴢴������µ���Ϣ, �ҵ��л���һ��ʱӦ������������
				i[j] = 1; // i[x]Ϊ��Ҫ����������� 
				weekOfFirstDay[j] = 0; // ÿ��һ�Ŷ�Ӧ������ 
			}// ��ѭ�����ڳ�ʼ������ i �� weekOfFirstDay 
			
			for(j = 0; j < 6; j++){ // ÿ�����6������ 
				for(k = 0; k < 3; k++){ // ÿ�麬3���� 
					weekTmp = 0; // weekTmp����ÿ�µ��������ڴ洢��ǰ������ַ�����Ӧ������ 
					printf("| ");
					for(; i[k] + weekOfFirstDay[k] - j * 7 <= 7; i[k]++){ // ÿ��ÿ���й���7���ַ���, ���Ⱦ�Ϊ4, ��ʽΪ"    "��" %2d "��" *%1d*"��"*%2d*" 
						if(i[k] <= maxDayPerMonth(year, 1 + k + 3 * h)){ // ʽ��(1 + k + 3 * h)��Ϊ�·� 
							if(i[k] == 1 && getWeek(year, 1 + k + 3 * h, 1) != weekTmp){ // ��weekTmp�����ڱ���һ�ն�Ӧ������i[k] == 1, ��˵�����ƻ�δ��ʼ, ����ո� 
								printf("    "); 
								weekOfFirstDay[k] = getWeek(year, 1 + k + 3 * h, 1);
								i[k]--; // û�������Ч����, ��i[k]����Ϊ1 
								weekTmp++;
							}
							else{ // ��i[k] != 1, ��˵�������Ѿ���ʼ; ��weekTmp���ڱ���һ�յ�����, ��������ڲ��������� 
								if(day == i[k] && month == 1 + k + 3 * h){
									if(i[k] / 10 == 0){
										printf(" "); // i[k] / 10 == 0 ? printf(" *%d*", i[k]); : printf("*%d*", i[k]); 
									}
									printf("*%d*", i[k]);
								}
								else{
									printf(" %2d ", i[k]);
								}
							}
						}
						else{
							printf("    "); // ���·�������Ч�����Ѿ�������, ����ո��� 
						}
					}
				}
				printf("|\n");
				
			}
		}
		printf("+-----------------------------+-----------------------------+-----------------------------+\n");
	}
	else{
		printf("+-----------------------------------------------------------------------------------------+\n"); // ��Ч��������Ч���ڶ�Ӧ��ͼ���߿�ͬ 
	}
	
	printf("|                                                                                         |\n");
	printf("|                 **                                             %s               |\n", date); // dateΪ����Ϊ10���ַ���, ����Ϊ"          "��"yyyy-mm-dd" 
	printf("|        ***      **                                                                      |\n");
	printf("|        ***      **                                 *********   ********** ***********   |\n");
	printf("|        ***      ****                                ***   ***      ***    **  ***  **   |\n");
	printf("|        ** **  ****                  *****           ***    ***     ***   **   ***   *   |\n");
	printf("|        ** ***   ****            ********            ***    ***     ***   **   ***   *   |\n");
	printf("|     ** ** **  *****          *******                ***    ***     ***        ***       |\n");
	printf("|     *******     **   ***          ***               ***    ***     ***        ***       |\n");
	printf("|        **       ********          **                ***   ***      ***        ***       |\n");
	printf("|        **** *****                 **                ********       ***        ***       |\n");
	printf("|  ********         ***             **                ***    ***     ***        ***       |\n");
	printf("|   **  ***    ********             **                ***     **     ***        ***       |\n");
	printf("|      ******  **    **             **                ***     ***    ***        ***       |\n");
	printf("|      ******   *******             **                ***     ***    ***        ***       |\n");
	printf("|     ** **    **    **             **                ***     ***    ***        ***       |\n");
	printf("|    *** **    **    **             ***********       ***     ***    ***        ***       |\n");
	printf("|    **  **    ***** **    ************       **      ***    ***     ***        ***       |\n");
	printf("|   **   **    **    ***    ****                     **********   *********    *****      |\n");
	printf("|        **    **    ***                                                                  |\n");
	printf("|        **    **  *****                                                                  |\n");
	printf("|        **         ***                                  http://online.bit.edu.cn/        |\n");
	printf("|                    **                                                                   |\n");
	printf("|                                                                                         |\n");
	printf("+-----------------------------------------------------------------------------------------+\n");
	
	system("PAUSE");
	return 0;
} 
