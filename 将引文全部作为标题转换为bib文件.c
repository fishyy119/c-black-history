#include <stdio.h>

// �س��ָ���س���ȫ�����ݾ���Ϊ���� 
int main(void){
	FILE *fout, *fin;
	char c;
	int num = 0, i, len = 0;
	fout = fopen("out.bib", "w");
	fin = fopen("in.txt", "r");
	
	
	while((c = fgetc(fin)) != EOF){
		if(c == '\n' && len != 0){
			fprintf(fout, "}\n}\n");
			len = 0;
			printf("%d\n", num);
		}
		else{
			if(len == 0){
				num++;
				fprintf(fout, "@misc{%d,\ntitle = {", num);
			}
			fprintf(fout, "%c", c);
			
			len++;
		}
	}
	
	return 0;
}
