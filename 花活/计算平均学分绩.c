#include <stdio.h>

int main(void){
	/***********************************
	文件第一行："科目数量：%d\n"
	文件第二行："成绩 学分\n" 
	以下若干行："%d %lf\n"
	************************************/
	FILE *fp = freopen("myGrade.txt", "r", stdin);
	if(fp == NULL){
		printf("err");
		return 0;
	}
	int n, i;
	double result = 0, sumCredit = 0;
	scanf("科目数量：%d（下列数据为：成绩 学分）", &n);
	for(i = 0; i < n; i++){
		int grade = 0;
		double credit = 0;
		scanf("%d%lf", &grade, &credit);
		result += grade * credit;
		sumCredit += credit;
	}
	printf("%lf", result / sumCredit);

	return 0;
}
