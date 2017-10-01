#include<stdio.h>
#include<stdlib.h>
 int map[20][20];//新建地图坐标
 struct food {
	 int xpost = 0;
	 int ypost = 0;
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
