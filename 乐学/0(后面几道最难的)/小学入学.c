#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct child{
	int numble;
	char birthday[11];
	char sex;
	char name[7];
};

int main(void){
	struct child child[181];
	int i, n = 0, j, k, year, month, day;
	for(i = 0; i < 180; i++){
		scanf("%d,%10s,%c,%6s", &child[n].numble, child[n].birthday, &child[n].sex, child[n].name);
		sscanf(child[n].birthday, "%d-%d-%d", &year, &month, &day);
		child[n].birthday[10] = '\0';
		for(k = strlen(child[n].name); k < 6; k++){
			child[n].name[k] = ' ';
		}
		child[n].name[6] = '\0';
		if(year == 2013 && month >= 9 || year > 2013){
//			i--;	
			n--;
		}
		n++;
	}
	for(j = n - 1; j > 0; j--){ // n 记录有效数据个数 
		for(k = 0; k < j; k++){
			if(child[k].numble > child[k + 1].numble){
				child[180] = child[k];
				child[k] = child[k + 1];
				child[k + 1] = child[180];
			}
		}
	}
	printf(" BH   BirthDay  Name  Sex\n-------------------------\n");
	for(j = 0; j < n; j++){
		printf("%04d %s %s %c\n", child[j].numble, child[j].birthday, child[j].name, child[j].sex);
	}
	system("PAUSE");
	return 0;
} 
