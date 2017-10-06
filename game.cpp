#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include<conio.h>
struct Food {
	int foodxpost = 0;
	int foodypost = 0;
	int FoodAlive = 1;
};//定义和存储食物的坐标和状态
Food food;
struct Post {
	int x;
	int y;
};//定义和存储坐标
Post post;
struct Snake {
	int direction = 1;
	int snakelong = 1;
	int snakealive = 1;
	Post snakepost[500]{};
};//定义和存储蛇的方向，长度，和所有蛇的位置
Snake snake;
void start();
int creatfood();
void getkey();
int move();
void print();
int main() {
	start();
	Food newfood = food;/*创建一个空食物和蛇方便下一次重新开始*/
	Snake newsnake = snake;
begin: food = newfood;/*重新开始的节点*/
	snake = newsnake;
	creatfood();
	while (snake.snakealive) {
		if (!move()) {
			break;
		}
		getkey();
		if (!food.FoodAlive) {
			creatfood();
		}
		system("cls");/*清屏函数 清楚屏幕上的所有数值*/;
		print();
		Sleep(500)/*休眠函数 暂停500ms*/;


	}
	printf("Game over!\n");
	printf("press y to restart!");
		char restart = _getch();
		if (restart == 'y') {
			goto begin;
		}
}
void start() {
	printf("Welcome to game!\n");
	printf("Press any key to start!");
	char c;
	scanf_s("%c", &c);
	system("cls");
}
int creatfood() {
	food.FoodAlive = 1;
	while (true) {
		int a = rand() % 20;
		int b = rand() % 20;
		int judge = 0;
		for (int i = 0; i < snake.snakelong; i++) {
			if (a == snake.snakepost[i].x && b == snake.snakepost[i].y)
				judge = 1;
		}
		if (judge == 0) {
			food.foodxpost = a;
			food.foodypost = b;
			return 0;
		}
	}
}
void getkey() {
	if (_kbhit()) {
		char key = _getch();
		if (key == 'd')
			snake.direction = 1;
		else if (key == 'w')
			snake.direction = 0;
		else if (key == 'a')
			snake.direction = 3;
		else if (key == 's')
			snake.direction = 2;
	}
}
int move() {
	Post defaultsnake = snake.snakepost[0];
	switch (snake.direction) {
	case 0:snake.snakepost[0].x--;
		break;
	case 1:snake.snakepost[0].y++;
		break;
	case 2:snake.snakepost[0].x++;
		break;
	case 3:snake.snakepost[0].y--;
		break;
	}
	if (snake.snakepost[0].x == food.foodxpost && snake.snakepost[0].y == food.foodypost) {
		for (int i = snake.snakelong - 1; i > 0; i--) {
			snake.snakepost[i + 1] = snake.snakepost[i];
		}
		snake.snakepost[1] = defaultsnake;
		food.FoodAlive = 0;
		snake.snakelong++;
	}
	else {
		for (int i = snake.snakelong - 2; i > 0; i--) {
			snake.snakepost[i + 1] = snake.snakepost[i];
		}
		snake.snakepost[1] = defaultsnake;
	}
	if (snake.snakepost[0].x == -1 || snake.snakepost[0].x == 20 || snake.snakepost[0].y == -1 || snake.snakepost[0].y == 20)
		return 0;
	return 1;
}
void print() {
	for (int i = 0; i < 22; i++) {
		printf("-");
	}
	printf("\n");
	for (int i = 0; i < 20; i++) {
		printf("|");
		for (int j = 0; j < 20; j++) {
			for (int k = 0; k < snake.snakelong; k++) {
				if (snake.snakepost[k].x == i && snake.snakepost[k].y == j) {
					printf("*");
					goto k;
				}
			}

			if ((food.foodxpost == i && food.foodypost == j))
				printf("#");
			else
				printf(" ");
		k:;
		}
		printf("|\n");
	}
	for (int i = 0; i < 21; i++) {
		printf("-");
	}
	printf("\n");
}