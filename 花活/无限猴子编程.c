#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <unistd.h>
#define True 1
#define False 0 
int main(void){  
	long t;
	printf("���޺��ӱ�̷�V1.0\n��������������������ȷ����Ŀ���(doge)\n"); 
	printf("�������ַ������ٶ�(��λ������/��)��");
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
