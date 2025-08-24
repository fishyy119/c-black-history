#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define backX 36
#define backY 22
#define stdDelay 10000

/**********************************************
V2.0�ƻ����
��ͼϵͳ�������ϰ����ͬ�ߴ糡�أ�
��ʼѡ�����***
��¼����ϴ����� 
�ߵ���ɫ����---
�����ص���ʼ���湦�� 
***********************************************/

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
/**********!!! ���Χ������Ͽ�2�У������������ڲ�����ת�������ڴ˾�������  !!!**********/
void readInUserDate(void); // ���뱾�ش洢����Ϣ 
void creatUserDate(void); // ����������Ϣ 
void writeOutUserDate(void); // ���±��ش洢��Ϣ 

void setBackground(int x, int y); /* ��x��y */  /* 1���������ռ��λ������ռһλ */ 
void setNewSnake(int x, int y); // �ṩ���ش�С������һ������Ϊ������
void setFood(int x, int y); // �ṩ���ش�С������ʳ�� 
void setInitialmenu(void); // ���ó�ʼ�˵� 
void setMenuSelectdifficulty(void); // ѡ���ѶȽ��� 
void setMenuChangeColor(void); // �ı���ɫ���� 

int judgeLife(int x, int y); // �ṩ���ش�С���ж�����  
int judgeCoordBlocked(int x, int y, snakeCoord c, int mode); // �ṩ���ش�С���ж�ĳһ�����Ƿ�����ռ�� 
int judgeFood(void); // �����Ƿ�Ե�ʳ�� 

void calculateHead(void); // ���㲢�洢������ͷ��λ��(�洢��ȫ�ֱ���snake��) 
void moveSnake(void); // �����ߵ���β�ƶ�
void changeHead(void); // ���������ͷ����
void changeTail(void); // ���������β���� 

int getOrder(void); // ��ȡ����ָ�� 
int getLastOrder(void); // ��ȡ���յļ���ָ��(�ڲ�����ѭ��getOrder����) 
void delay(int n);

/***************************************************************
�ߵ��ƶ�˳��                                
1��������β 
2���滻��ͷ����Ϊ����
3��������ͷλ�ò�����snake.ht[0]
4��������ͷ
5���ı�������ͷ����
6���ı�������β����
7�����ݴ������ͷ�����Ƿ���������ͷλ���Ƿ�ͬʱ��������ռ�ݣ� 
*****************************************************************/

body *pSnake;
HANDLE handle;
snakeCoord food;
int score = 2;
COORD scoreCoord;
char difficulty, snakeColor;
FILE *dateFile;
int debug;


int main(void){
	pSnake = (body*)malloc(sizeof(body)); // �������� 
	handle = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ���ھ�� 
	readInUserDate(); // ���뱾������ 
	
	setInitialmenu();
	setBackground(backX, backY);
	setNewSnake(backX, backY);
	setFood(backX, backY);
	
	while(judgeLife(backX, backY)){
		moveSnake();
		delay(stdDelay);
	}
	
	
	
	
	
//	SetConsoleCursorPosition(handle, coordTransform((snakeCoord){snake.h.X + 5, snake.h.Y}));
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n %d ", debug);
//	system("pause");
	return 0;
}

COORD coordTransform(snakeCoord t){
	COORD result;
	result.X = t.X * 2 - 1;
	result.Y = t.Y + 2;
	return result;
}

void readInUserDate(void){
	dateFile = fopen("GoodSnakeDate.snake", "rb+");
	if(dateFile == NULL){
		creatUserDate();
	}
	fread(&difficulty, 1, 1, dateFile);
	fread(&snakeColor, 1, 1, dateFile);
}

void creatUserDate(void){
	char d = 3, c = 16; // ��ʼ���Ѷȡ���ɫ 
	dateFile = fopen("GoodSnakeDate.snake", "wb");
	fwrite(&d, 1, 1, dateFile);
	fwrite(&c, 1, 1, dateFile);
	readInUserDate(); 
}

void writeOutUserDate(void){
	fseek(dateFile, 0, SEEK_SET);
	fwrite(&difficulty, 1, 1, dateFile);
	fwrite(&snakeColor, 1, 1, dateFile);
}

void setBackground(int x, int y){
	system("cls");
	SetConsoleCursorPosition(handle, (COORD){0, 0});
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

void setInitialmenu(void){
	COORD menu;
	int i;
	while(1){
		system("cls");
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 0x0f);
		menu.X = 15; menu.Y = 1;
		for(i = 0; i < 7; i++){
			SetConsoleCursorPosition(handle, menu);
			switch(i){
				case 0: printf("̰����V2.0\n"); break;
				case 1: printf("1.��ʼ��Ϸ"); break;
				case 2: printf("2.ѡ���Ѷ�"); break; 
				case 3: printf("3.�ı��ߵ���ɫ"); break;
				case 4: printf("4.�˳�"); break;	
			}
			menu.Y += 2;
		}
		switch(_getch()){
			case '1': case 13: return; break;
			case '2': setMenuSelectdifficulty(); break;
			case '3': setMenuChangeColor(); break;
			case '4': exit(0);
			default: break;
		}
	}
}

void setMenuSelectdifficulty(void){
	system("cls");
	int i;
	COORD selectDifficulty = {15, 2};
	SetConsoleCursorPosition(handle, selectDifficulty);
	printf("�Ѷ�ѡ��");
	for(i = 1; i <= 5; i++){
		selectDifficulty.Y += 2;
		if(i == difficulty){
			SetConsoleTextAttribute(handle, 0x0a);
		}
		else{
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 0x00);
		}
		SetConsoleCursorPosition(handle, selectDifficulty);
		printf("�Ѷ�%d", i);
	}
	char num;
	while((num = _getch()) != 13){ // ����س����˻����˵� 
	num = ((num - '0') >= 1 && (num - '0') <= 5) ? num - '0' : difficulty; // ��ȡ��Ч������ 
	selectDifficulty.Y = 2 * difficulty + 2;
	SetConsoleCursorPosition(handle, selectDifficulty);
	SetConsoleTextAttribute(handle, 0x08);
	printf("�Ѷ�%d", difficulty);
	selectDifficulty.Y = 2 * num + 2;
	SetConsoleCursorPosition(handle, selectDifficulty);
	SetConsoleTextAttribute(handle, 0x0a);
	printf("�Ѷ�%d", num); // �л�������ʾ 
	difficulty = num;
	}
	writeOutUserDate(); 
	return;
}

void setMenuChangeColor(void){
	system("cls");
	int i;
	COORD selectDifficulty = {15, 2};
	SetConsoleCursorPosition(handle, selectDifficulty);
	printf("�ı��ߵ���ɫ");
	while(1){
		;
	}
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
		case 72: case 'w': case 'W': input = 2; break; // ��ͷ��WSAD 
		case 80: case 's': case 'S': input = 8; break;
		case 75: case 'a': case 'A': input = 1; break;
		case 77: case 'd': case 'D': input = 9; break;
		default: input = 0;
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
	debug = input;
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
	int key[2] = {0, 0}; // û�������򷵻�0 
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


