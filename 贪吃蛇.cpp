#include<stdio.h>
#include<stdlib.h>
 int map[20][20];//�½���ͼ����
 struct food {
	 int xpost = 0;
	 int ypost = 0;
	 int FoodAlive = 1;
 };//����ʳ��������״̬
 struct post {
	 int snakexpost = 10;
	 int snakeypost = 10;
 };//������ͷ������
 struct snake {
	 int direction = 1;
	 int snakelong = 1;
	 int snakealive = 1;
	 post p[200]{};
 };//�����ߵķ��򣬳��ȣ��������ߵ�λ��
