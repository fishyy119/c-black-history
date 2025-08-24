#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define backX 36
#define backY 22
#define stdDelay 10000

/******************************************************
̰����V1.0
�̶��ĳ���
�̶����ٶ�
���ϰ��� 
ʵ���˻�����̰�����ж�������������- 
*******************************************************/

typedef struct{ // ������ 
	short X; short Y;
}snakeCoord; // �Ա߿����Ͻ�Ϊԭ�㣬����Ϊx����������Ϊy������ 

typedef struct snakeBody{ // �������� 
	snakeCoord coord; /********  ֱ����ָ��pSnake���ӵ�body�в��洢����  ********/
	struct snakeBody *next;
}body;

struct snake{ // ����β(�����ߵ��˶�) 
	snakeCoord ht[2]; //�ֱ�Ϊͷ��β
	short direction; // 2 - up, 8 - down, 1 - left, 9 - right ���෴����ĺ�Ϊ10 
}snake;

COORD coordTransform(snakeCoord t); // �����Χ�ڲ�������ת��Ϊ����̨����(��Ӧ�����һλ��ʼ) 
void setBackground(int x, int y); /* ��x��y */  /* 1���������ռ��λ������ռһλ */ 
void setNewSnake(int x, int y); // �ṩ���ش�С������һ������Ϊ������
void setFood(int x, int y); // �ṩ���ش�С������ʳ�� 
int judgeLife(int x, int y); // �ṩ���ش�С���ж�����  
int judgeCoordBlocked(int x, int y, snakeCoord c, int mode); // �ṩ���ش�С���ж�ĳһ�����Ƿ�����ռ�� 
int judgeFood(void); // �����Ƿ�Ե�ʳ�� 
void calculateHead(void); // ���㲢�洢������ͷ��λ�� 
void moveSnake(void); // �����ߵ���β�ƶ�
void changeHead(void); // ���������ͷ����
void changeTail(void); // ���������β���� 
int getOrder(void); // ��ȡ����ָ�� 
int getLastOrder(void); // ��ȡ���յļ���ָ��(�ڲ�����ѭ��getOrder����) 
void delay(int n);

body *pSnake;
HANDLE handle;
snakeCoord food;
int score = 2;
COORD scoreCoord;


int main(void){
	pSnake = (body*)malloc(sizeof(body));
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	setBackground(backX, backY);
	setNewSnake(backX, backY);
	setFood(backX, backY);
	
	while(judgeLife(backX, backY)){
		moveSnake();
		delay(stdDelay);
	}
	
	
	
	
	
//	SetConsoleCursorPosition(handle, coordTransform((snakeCoord){snake.h.X + 5, snake.h.Y}));
	system("pause");
	return 0;
}

COORD coordTransform(snakeCoord t){
	COORD result;
	result.X = t.X * 2 - 1;
	result.Y = t.Y + 2;
	return result;
}

void setBackground(int x, int y){
	printf("���ؿ��:%d*%d                                       ���߳���=%d\n\n", x, y, score);
	scoreCoord = (COORD){62, 0}; // ����������x y�Ŀ�� 
	int i, j;
	for(i = 0; i <= y + 1; i++){
		for(j = 0; j <= x + 1; j++){
			if(j == 0 || j == x + 1){
				if(i == 0 || i == y + 1){
					printf("+");
				}
				else{
					printf("|");
				}
			}
			else{
				if(i == 0 || i == y + 1){
					printf("--"); 
				}
				else{
					printf("  ");
				}
			}
			if(j == x + 1){
				printf("\n");
			}
		}
	}
}

void setNewSnake(int x, int y){
	int i;
	body *t = pSnake;
	for(i = 0; i < 2; i++){
		snake.ht[i] = (snakeCoord){x / 2 - i, y / 2};
		t -> next = (body*)malloc(sizeof(body));
		t -> next -> coord = snake.ht[i];
		t -> next -> next = NULL;
		t = t -> next;
	}
	snake.direction = 9;
	SetConsoleCursorPosition(handle, coordTransform(snake.ht[1]));
	printf("##@@");
}

void setFood(int x, int y){
	srand(time(NULL));
	do{
		food.X = rand() % x + 1;
		food.Y = rand() % y + 1;
	}while(judgeCoordBlocked(backX, backY, food, 2) == 0);
	SetConsoleCursorPosition(handle, coordTransform(food));
	printf("**");
}

int judgeLife(int x, int y){ // �����ڼ�����ͷ������ɾ���˾�β�ͼ�������ͷ������ 
	body *t = pSnake;
	if(snake.ht[0].X == x + 1 || snake.ht[0].X == 0 || snake.ht[0].Y == y + 1 || snake.ht[0].Y == 0){
		return 0; // �����߽����� 
	}
	return judgeCoordBlocked(backX, backY, snake.ht[0], 1);
}

int judgeCoordBlocked(int x, int y, snakeCoord c, int mode){ // mode1�����ж������Ҫ������ͷ��mode2��������ʳ���������ͷ 
	body *t = pSnake;
	if(mode == 1){
		t = t -> next; // ��������ͷ
	} 
	while(t -> next != NULL){
		if(t -> next -> coord.X == c.X && t -> next -> coord.Y == c.Y){
			return 0; // Ŀ������c�ѱ�ռ�� 
		}
		t = t -> next;
	}
	return 1;	
}

int judgeFood(void){ // �Ѿ���������ͷ���� 
	if(food.X == snake.ht[0].X && food.Y == snake.ht[0].Y){
		return 1;
	}
	return 0;
}

void calculateHead(void){
	int input = getLastOrder();
	switch(input){
		case 72: case 119: input = 2; break; // ��ͷ��WSAD 
		case 80: case 115: input = 8; break;
		case 75: case 97: input = 1; break;
		case 77: case 100: input = 9; break;
	}
	if(input != 0 && input + snake.direction != 10){ // �����ָ���ԭ����ķ����� 
		snake.direction = input;
	}
	switch(snake.direction){
		case 2: snake.ht[0].Y--; break;
		case 1: snake.ht[0].X--; break;
		case 9: snake.ht[0].X++; break;
		case 8: snake.ht[0].Y++; break;
	}	
}

void moveSnake(void){
	SetConsoleCursorPosition(handle, coordTransform(snake.ht[1]));
	printf("  "); // ɾ����β�� 
	SetConsoleCursorPosition(handle, coordTransform(snake.ht[0]));
	printf("##"); // �滻��ͷͼ��
	calculateHead();
	SetConsoleCursorPosition(handle, coordTransform(snake.ht[0]));
	printf("@@");
	changeHead();
	changeTail();

}

void changeHead(void){ // �Ѿ���������ͷ���� 
	body *t = pSnake -> next;
	pSnake -> next = (body*)malloc(sizeof(body));
	pSnake -> next -> coord = snake.ht[0];
	pSnake -> next -> next = t;
}

void changeTail(void){ // �Ѿ���������ͷ���� 
	if(judgeFood() == 0){ // δ�Ե�ʳ�� 
		body *t = pSnake;
		while(t -> next -> next != NULL){
			t = t -> next;
		}
		free(t -> next);
		t -> next = NULL;
		snake.ht[1] = t -> coord;
	}
	else{
		score++;
		SetConsoleCursorPosition(handle, scoreCoord);
		printf("%d", score);
		setFood(backX, backY);
	}
}

int getOrder(void){
	int result = 0;
	if(_kbhit()){
		result = _getch();
		if(result == 224){
			result = _getch();
		}
	}
	return result;
}

int getLastOrder(void){ // ��һ������������������Ϊ��Чָ�� 
	int key[2] = {}; // û�������򷵻�0 
	int i = 0;
	do{
		i %= 2;
		key[i] = getOrder();
		i++;
	}while(key[i - 1] != 0);
	return key[i % 2];
}

void delay(int n){
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < 60000; j++);
}


