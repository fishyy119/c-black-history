#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <unistd.h>
#define True 1
#define False 0 
int main(void){  
	long t;
	printf("无限猴子编程法V1.0\n理论上来讲存在生成正确程序的可能(doge)\n"); 
	printf("请输入字符弹出速度(单位：毫秒/个)：");
	scanf("%ld", &t);
	printf("--------------------------------------------------------\n");
	char dictionary[95] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\n1234567890-=!@#$%^&*()_+~`<>?:\",./;'[]{}|\\"; 
	srand(time(NULL));
	while(True){
		printf("%c", dictionary[rand() % 95]);
		usleep(1000 * t);
	}
	return 0; 
}  
