#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define backX 36
#define backY 22
#define stdDelay 10000

/******************************************************
贪吃蛇V1.0
固定的场地
固定的速度
无障碍物 
实现了基本的贪吃蛇行动、生长、死亡- 
*******************************************************/

typedef struct{ // 蛇坐标 
	short X; short Y;
}snakeCoord; // 以边框左上角为原点，向右为x正方向，向下为y正方向 

typedef struct snakeBody{ // 蛇身链表 
	snakeCoord coord; /********  直接与指针pSnake链接的body中不存储坐标  ********/
	struct snakeBody *next;
}body;

struct snake{ // 蛇首尾(用于蛇的运动) 
	snakeCoord ht[2]; //分别为头、尾
	short direction; // 2 - up, 8 - down, 1 - left, 9 - right 让相反方向的和为10 
}snake;

COORD coordTransform(snakeCoord t); // 将活动范围内部的坐标转换为控制台坐标(相应格的左一位起始) 
void setBackground(int x, int y); /* 横x竖y */  /* 1个方格横向占两位，纵向占一位 */ 
void setNewSnake(int x, int y); // 提供场地大小，创建一个长度为二的蛇
void setFood(int x, int y); // 提供场地大小，生成食物 
int judgeLife(int x, int y); // 提供场地大小，判断死活  
int judgeCoordBlocked(int x, int y, snakeCoord c, int mode); // 提供场地大小，判断某一坐标是否被蛇身占用 
int judgeFood(void); // 计算是否吃到食物 
void calculateHead(void); // 计算并存储接下来头的位置 
void moveSnake(void); // 处理蛇的首尾移动
void changeHead(void); // 处理链表的头部分
void changeTail(void); // 处理链表的尾部分 
int getOrder(void); // 获取键盘指令 
int getLastOrder(void); // 获取最终的键盘指令(内部不断循环getOrder函数) 
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
	printf("场地宽度:%d*%d                                       蛇蛇长度=%d\n\n", x, y, score);
	scoreCoord = (COORD){62, 0}; // 坐标依赖于x y的宽度 
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

int judgeLife(int x, int y){ // 依赖于计算后的头坐标与删除了旧尾巴加入了新头的链表 
	body *t = pSnake;
	if(snake.ht[0].X == x + 1 || snake.ht[0].X == 0 || snake.ht[0].Y == y + 1 || snake.ht[0].Y == 0){
		return 0; // 碰触边界死亡 
	}
	return judgeCoordBlocked(backX, backY, snake.ht[0], 1);
}

int judgeCoordBlocked(int x, int y, snakeCoord c, int mode){ // mode1用于判断死活，需要跳过新头；mode2用于生成食物，不跳过新头 
	body *t = pSnake;
	if(mode == 1){
		t = t -> next; // 跳过了新头
	} 
	while(t -> next != NULL){
		if(t -> next -> coord.X == c.X && t -> next -> coord.Y == c.Y){
			return 0; // 目标坐标c已被占据 
		}
		t = t -> next;
	}
	return 1;	
}

int judgeFood(void){ // 已经计算完新头坐标 
	if(food.X == snake.ht[0].X && food.Y == snake.ht[0].Y){
		return 1;
	}
	return 0;
}

void calculateHead(void){
	int input = getLastOrder();
	switch(input){
		case 72: case 119: input = 2; break; // 箭头与WSAD 
		case 80: case 115: input = 8; break;
		case 75: case 97: input = 1; break;
		case 77: case 100: input = 9; break;
	}
	if(input != 0 && input + snake.direction != 10){ // 输入的指令不是原方向的反方向 
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
	printf("  "); // 删除旧尾巴 
	SetConsoleCursorPosition(handle, coordTransform(snake.ht[0]));
	printf("##"); // 替换旧头图案
	calculateHead();
	SetConsoleCursorPosition(handle, coordTransform(snake.ht[0]));
	printf("@@");
	changeHead();
	changeTail();

}

void changeHead(void){ // 已经计算完新头坐标 
	body *t = pSnake -> next;
	pSnake -> next = (body*)malloc(sizeof(body));
	pSnake -> next -> coord = snake.ht[0];
	pSnake -> next -> next = t;
}

void changeTail(void){ // 已经计算完新头坐标 
	if(judgeFood() == 0){ // 未吃到食物 
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

int getLastOrder(void){ // 将一个周期内最后的输入作为有效指令 
	int key[2] = {}; // 没有输入则返回0 
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


