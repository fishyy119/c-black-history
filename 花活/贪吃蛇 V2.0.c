#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define backX 36
#define backY 22
#define stdDelay 10000

/**********************************************
V2.0计划添加
地图系统（包括障碍物，不同尺寸场地）
初始选择界面***
记录玩家上次设置 
蛇的颜色更改---
死亡回到初始界面功能 
***********************************************/

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
/**********!!! 活动范围框必须上空2行，左侧紧贴，其内部坐标转换依赖于此绝对坐标  !!!**********/
void readInUserDate(void); // 读入本地存储的信息 
void creatUserDate(void); // 创建本地信息 
void writeOutUserDate(void); // 更新本地存储信息 

void setBackground(int x, int y); /* 横x竖y */  /* 1个方格横向占两位，纵向占一位 */ 
void setNewSnake(int x, int y); // 提供场地大小，创建一个长度为二的蛇
void setFood(int x, int y); // 提供场地大小，生成食物 
void setInitialmenu(void); // 设置初始菜单 
void setMenuSelectdifficulty(void); // 选择难度界面 
void setMenuChangeColor(void); // 改变颜色界面 

int judgeLife(int x, int y); // 提供场地大小，判断死活  
int judgeCoordBlocked(int x, int y, snakeCoord c, int mode); // 提供场地大小，判断某一坐标是否被蛇身占用 
int judgeFood(void); // 计算是否吃到食物 

void calculateHead(void); // 计算并存储接下来头的位置(存储在全局变量snake中) 
void moveSnake(void); // 处理蛇的首尾移动
void changeHead(void); // 处理链表的头部分
void changeTail(void); // 处理链表的尾部分 

int getOrder(void); // 获取键盘指令 
int getLastOrder(void); // 获取最终的键盘指令(内部不断循环getOrder函数) 
void delay(int n);

/***************************************************************
蛇的移动顺序：                                
1，消除旧尾 
2，替换旧头材质为身体
3，计算新头位置并存入snake.ht[0]
4，绘制新头
5，改变链表中头部分
6，改变链表中尾部分
7，根据存入的新头计算是否死亡（新头位置是否同时被蛇身体占据） 
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
	pSnake = (body*)malloc(sizeof(body)); // 创建链表 
	handle = GetStdHandle(STD_OUTPUT_HANDLE); // 获取窗口句柄 
	readInUserDate(); // 读入本地数据 
	
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
	char d = 3, c = 16; // 初始的难度、颜色 
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
				case 0: printf("贪吃蛇V2.0\n"); break;
				case 1: printf("1.开始游戏"); break;
				case 2: printf("2.选择难度"); break; 
				case 3: printf("3.改变蛇的颜色"); break;
				case 4: printf("4.退出"); break;	
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
	printf("难度选择");
	for(i = 1; i <= 5; i++){
		selectDifficulty.Y += 2;
		if(i == difficulty){
			SetConsoleTextAttribute(handle, 0x0a);
		}
		else{
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 0x00);
		}
		SetConsoleCursorPosition(handle, selectDifficulty);
		printf("难度%d", i);
	}
	char num;
	while((num = _getch()) != 13){ // 输入回车则退回主菜单 
	num = ((num - '0') >= 1 && (num - '0') <= 5) ? num - '0' : difficulty; // 获取有效的数据 
	selectDifficulty.Y = 2 * difficulty + 2;
	SetConsoleCursorPosition(handle, selectDifficulty);
	SetConsoleTextAttribute(handle, 0x08);
	printf("难度%d", difficulty);
	selectDifficulty.Y = 2 * num + 2;
	SetConsoleCursorPosition(handle, selectDifficulty);
	SetConsoleTextAttribute(handle, 0x0a);
	printf("难度%d", num); // 切换高亮显示 
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
	printf("改变蛇的颜色");
	while(1){
		;
	}
}

int judgeLife(int x, int y){ // 依赖于计算后的头坐标与删除了旧尾巴加入了新头的链表 
	body *t = pSnake;
	if(snake.ht[0].X == x + 1 || snake.ht[0].X == 0 || snake.ht[0].Y == y + 1 || snake.ht[0].Y == 0){
		return 0; // 碰触边界死亡 
	}
	return judgeCoordBlocked(backX, backY, snake.ht[0], 1);
}

int judgeCoordBlocked(int x, int y, snakeCoord c, int mode){ // mode1用于判断死活，需要忽略新头；mode2用于生成食物，不忽略新头 
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
		case 72: case 'w': case 'W': input = 2; break; // 箭头与WSAD 
		case 80: case 's': case 'S': input = 8; break;
		case 75: case 'a': case 'A': input = 1; break;
		case 77: case 'd': case 'D': input = 9; break;
		default: input = 0;
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
	debug = input;
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
	int key[2] = {0, 0}; // 没有输入则返回0 
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


