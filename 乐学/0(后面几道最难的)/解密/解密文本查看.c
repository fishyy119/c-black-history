#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PassStru{ // �����ṹ: ����(4�ֽ�),���ĳ���(2�ֽ�),Կ��(1�ֽ�) 
	unsigned int Offset; 
	unsigned short int Size; 
	unsigned char Key; 
	char extra;
	};


int main(void){
	struct PassStru PassStru;
	int n, i, j;
	char path[20], text[70000], strSN[50], strMD[50];
	scanf("%s", path);
	scanf("%d", &n);
	FILE *fp = fopen(path ,"rb");
	for(i = 0; i < 5; i++){
		fseek(fp, 8 * 66 * i, SEEK_SET); // ��λ�������"0i"��ͷ 
		fseek(fp, 8 * n - 8, SEEK_CUR); // ��λ�������"0i-n"��ͷ 
		fread(&PassStru, 8, 1, fp);
		fseek(fp, PassStru.Offset, SEEK_SET); // ��λ������n�Ŀ�ͷ
		for(j = 0; j < PassStru.Size; j++){
			fread(text + j, 1, 1, fp);
			text[j] += PassStru.Key;
		} 
		text[j] = '\0';
		if(strstr(text, "Wrong Key!") == text){
			continue;
		}
//		printf("XH: %02d\n", n);
//		strncpy(strSN, strstr(text, "Serial No.:") + 12, 19);
//		strncpy(strMD, strstr(text, "MD9:") + 5, 32);
//		printf("SN: %s\n", strSN);
//		printf("M9: %s\n", strMD);
		puts(text); 
		break;
	}
	system("pause"); 
	return 0;
} 
