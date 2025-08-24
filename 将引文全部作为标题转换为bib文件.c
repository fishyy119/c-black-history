#include <stdio.h>

// 回车分割，除回车外全部内容均视为标题 
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
