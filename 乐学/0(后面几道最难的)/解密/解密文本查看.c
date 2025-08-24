#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PassStru{ // 密码表结构: 编移(4字节),密文长度(2字节),钥匙(1字节) 
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
		fseek(fp, 8 * 66 * i, SEEK_SET); // 定位到密码表"0i"开头 
		fseek(fp, 8 * n - 8, SEEK_CUR); // 定位到密码表"0i-n"开头 
		fread(&PassStru, 8, 1, fp);
		fseek(fp, PassStru.Offset, SEEK_SET); // 定位到密文n的开头
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
