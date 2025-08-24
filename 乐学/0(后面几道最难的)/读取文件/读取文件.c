#include <stdio.h>
#include <string.h>

int main(void){
	FILE *fp;
	char fileName[500], c;
	gets(fileName);
	fp = fopen(fileName, "r");
//	while(!feof(fp)){
//		if((c = fgetc(fp)) != EOF){
////			printf("%c", c);
//putchar(c);
//		}
//	}
	while((c = fgetc(fp)) != EOF)
		putchar(c);
	
//	fclose(fp);
	return 0;
}
