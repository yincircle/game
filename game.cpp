#include<stdio.h>
#include<stdlib.h>
 int map[20][20];//新建地图坐标
 struct food {
	 int foodxpost = 0;
	 int foodypost = 0;
	 int FoodAlive = 1;
 };//定义食物的坐标和状态
 struct post {
	 int snakexpost = 10;
	 int snakeypost = 10;
 };//定义蛇头的坐标
 struct snake {
	 int direction = 1;
	 int snakelong = 1;
	 int snakealive = 1;
	 post p[200]{};
 };//定义蛇的方向，长度，和所有蛇的位置
 int main() {
	 void print_map(); /*打印*/{
		 int p, q;
		 for (p = 0; p < 21; p++) {
			 for (q = 0; q < 21; q++) {
				 if (map[p][q] == 0/*0代表空白*/) {
					 printf(" ");
				 }
				 else if (map[p][q] == 1/*1代表蛇*/) {
					 printf("*");
				 }
				 else if (map[p][q] == 2/*2代表食物*/) {
					 printf("#");
				 }
				 else if (map[p][q] == 3/*3代表边界*/) {
					 printf("%");
				 }
			 }
		 }

	 }
  }
