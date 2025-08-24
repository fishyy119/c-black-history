#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct XsStru{
	unsigned int ID;
	char Name[9]; // ʵ����Name[8]�洢��Sex��Ϊ�����ʱNameĩβ��NUL�ַ����ڶ������ݺ����滻 
	unsigned char Km1;
	unsigned char Km2;
	unsigned char Km3;
	char Sex;
	};

int main(void){
	struct XsStru competitor[101];
	int n = 0, i ,j; // n��¼ѡ������
	int sameMark = 0, insert = 0;
	char path[20];
	gets(path);
	FILE *fp = fopen(path, "rb");
	while(!feof(fp)){
		insert = 0;
		sameMark = 0;
		fread(competitor + 100, 16, 1, fp);
		competitor[100].Sex = competitor[100].Name[8];
		competitor[100].Name[8] = '\0';
		for(i = 0; i < (n < 99 ? n : 99); i++){ // ����гɼ��ȶ� 
			if(competitor[100].Km1 + competitor[100].Km2 + competitor[100].Km3 > competitor[i].Km1 + competitor[i].Km2 + competitor[i].Km3){
				insert = 1;
			}
			else if(competitor[100].Km1 + competitor[100].Km2 + competitor[100].Km3 == competitor[i].Km1 + competitor[i].Km2 + competitor[i].Km3){
				sameMark = 1;
				if(competitor[100].ID < competitor[i].ID){
					insert = 1;
				}
			}
			else if(sameMark == 1){ // ˵����ID�ڷ�����ͬ�Ĳ����������
				i--; 
				insert = 1;
			}
			if(insert == 1){
				for(j = (n < 99 ? n : 99); j > i; j--){ // ������� 
					competitor[j] = competitor[j - 1];
				}
				competitor[i] = competitor[100]; // �������� 
				break;
			}
		}
		if(n <= 98 && insert == 0){ // ��ĩβ�������� 
			competitor[n] = competitor[100];
		}
//		if(/*competitor[100].ID == 0*/n == 23456){
//			printf(" ");
//		}
		n++;
	}
	printf("+-----------------------------------------------------+\n");
	printf("|                   TOP 99 of %-6d                  |\n", n - 1); // ��¼��n���һ(�ļ�ĩ���ж��IDΪ0������)
	printf("+-----+--------+----------+---+-----+-----+-----+-----+\n");
	printf("| TOP |   ID   |   Name   |Sex| SUM | KM1 | KM2 | KM3 |\n");
	for(i = 0; i < 20; i++){
		printf("+-----+--------+----------+---+-----+-----+-----+-----+\n");
		for(j = 0; j < 5; j++){
			int index = i * 5 + j;
			if(index == 99){
				break;
			}
			printf("| %2d  | %06d | %s | %c | %3d | %3d | %3d | %3d |\n", index + 1, competitor[index].ID, competitor[index].Name, competitor[index].Sex, \
			competitor[index].Km1 + competitor[index].Km2 + competitor[index].Km3, competitor[index].Km1, competitor[index].Km2, competitor[index].Km3);  
		}
	}
	printf("+-----+--------+----------+---+-----+-----+-----+-----+\n");
	return 0;
} 
