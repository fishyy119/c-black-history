#include <stdio.h>
#include <stdlib.h>
//24,HZK24K.dot
//48,HZK48.dot
int main(void){
	
	char fileName[100], date, background, foreground;
	int n, position;
	FILE *fp;
	int i, j, k, count, Bin[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	scanf("%d,%s", &n, &fileName);
	scanf("%d,%c,%c", &position, &background, &foreground);
	fp = fopen(fileName, "r");
	fseek(fp, ((position / 100 - 1) * 94 + position % 100 - 1) * (n * (n / 8 + (n % 8 != 0))), SEEK_SET); // ��n����8�ı���, ��(n % 8 != 0)��ֵΪһ 
	for(i = 0; i < n; i++){ // ��������
		count = 0;
		for(j = 0; j < (n / 8 + (n % 8 != 0)); j++){ // �洢ÿ�����ݵ��ֽ�(��n % 8 != 0, ����ȥһ���ֶ��������) 
			date = fgetc(fp);
			for(k = 0; k < 8; k++){ // ȡ��ÿһ��������λ 
				if(count <= n){
					if((date & Bin[k]) == Bin[k]){
						printf("%c ", foreground);
					}
					else{
						printf("%c ", background);
					}
				}
				count++;
			}
		}
		printf("\n");
	}
	system("PAUSE");
	return 0;
}
