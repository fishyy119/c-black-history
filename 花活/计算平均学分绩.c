#include <stdio.h>

int main(void){
	/***********************************
	�ļ���һ�У�"��Ŀ������%d\n"
	�ļ��ڶ��У�"�ɼ� ѧ��\n" 
	���������У�"%d %lf\n"
	************************************/
	FILE *fp = freopen("myGrade.txt", "r", stdin);
	if(fp == NULL){
		printf("err");
		return 0;
	}
	int n, i;
	double result = 0, sumCredit = 0;
	scanf("��Ŀ������%d����������Ϊ���ɼ� ѧ�֣�", &n);
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
