#include <stdio.h>
#include <stdlib.h> 

int getWeek(int y, int m, int d){
	if(m == 1 || m == 2){
		y--;
		m += 12; // 公式要求: 1 2月视为去年13 14月 
	}
	return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
} // Monday --> 0，Tuesday --> 1, ... , Sunday --> 6 

int maxDayPerMonth(int y, int m){ // 每月最大天数 
	int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(m == 2){
		if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
			return 1 + a[m - 1];
		}
	}
	return a[m - 1];
}

int isTrueDate(int y, int m, int d){
	if(y <= 3000 && y >= 1000){ // 年份限制 
		if(m <= 12 && m >= 1){ // 月份限制 
			if(d <= maxDayPerMonth(y, m) && d >= 1){ // 日期限制 
				return 1;
			}
		}
	}
	return 0;
}

int main(void){
	char date[11] = "          "; // 共10个空格 
	int year, day, month;
	int h, j, k;
	int weekTmp = 0;
	int i[3], weekOfFirstDay[3];
	scanf("%d-%d-%d", &year, &month, &day);
	
	if(isTrueDate(year, month, day)){ // 当输入日期合法时 
		sprintf(date, "%d-%02d-%02d", year, month, day); // 形如yyyy-mm-dd,长度为10 
		printf("+-----------------------------------------------------------------------------------------+\n");
		printf("|                                                                                         |\n");
		printf("|                               Calendar of Year [%2d%2d%2d%2d ]                              |\n", year / 1000, year / 100 % 10, year / 10 % 10, year % 10);
		printf("|                                                                                         |\n");
		
		for(h = 0; h < 4; h++){ // 将日历分为4块 
			printf("+-----------------------------+-----------------------------+-----------------------------+\n");
			switch(h){ // 根据块的序号, 输出表格中的月份信息 
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
			
			for(j = 0; j < 3; j++){ // 每块的三个月需要并行输出, 故用长度为3的数组分别储存三个月的信息, 且当切换下一块时应重置其中数据
				i[j] = 1; // i[x]为将要被输出的日期 
				weekOfFirstDay[j] = 0; // 每月一号对应的星期 
			}// 此循环用于初始化数组 i 与 weekOfFirstDay 
			
			for(j = 0; j < 6; j++){ // 每月输出6行日期 
				for(k = 0; k < 3; k++){ // 每块含3个月 
					weekTmp = 0; // weekTmp仅在每月的首行用于存储当前待输出字符串对应的星期 
					printf("| ");
					for(; i[k] + weekOfFirstDay[k] - j * 7 <= 7; i[k]++){ // 每行每月中共有7个字符串, 长度均为4, 形式为"    "或" %2d "或" *%1d*"或"*%2d*" 
						if(i[k] <= maxDayPerMonth(year, 1 + k + 3 * h)){ // 式中(1 + k + 3 * h)即为月份 
							if(i[k] == 1 && getWeek(year, 1 + k + 3 * h, 1) != weekTmp){ // 若weekTmp不等于本月一日对应星期且i[k] == 1, 则说明递推还未开始, 输出空格 
								printf("    "); 
								weekOfFirstDay[k] = getWeek(year, 1 + k + 3 * h, 1);
								i[k]--; // 没有输出有效数据, 将i[k]控制为1 
								weekTmp++;
							}
							else{ // 若i[k] != 1, 则说明递推已经开始; 若weekTmp等于本月一日的星期, 则输出日期并启动递推 
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
							printf("    "); // 该月份所有有效日期已经输出完毕, 输出空格补齐 
						}
					}
				}
				printf("|\n");
				
			}
		}
		printf("+-----------------------------+-----------------------------+-----------------------------+\n");
	}
	else{
		printf("+-----------------------------------------------------------------------------------------+\n"); // 有效日期与无效日期对应的图案边框不同 
	}
	
	printf("|                                                                                         |\n");
	printf("|                 **                                             %s               |\n", date); // date为长度为10的字符串, 内容为"          "或"yyyy-mm-dd" 
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
