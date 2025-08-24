#include <stdio.h>
#include <string.h>

char str[1000];

int judge(int x){
	if(x > (strlen(str) - 1) / 2 || strlen(str) == 0){
		return 1;
	}
	if(str[x] == str[strlen(str) - x - 1] && x <= (strlen(str) - 1) / 2){
		judge(x + 1);
	}
	else{
		return 0;
	}	
}

int main(void){
	gets(str);
	if(judge(0) == 1){
		printf("Yes\n");
	}
	else if(judge(0) == 0){
		printf("No\n");
	}
	return 0;
}
//  问题为当strlen == 0 原先的程序判断为否,改进为在第一个if加入||后的判断 
