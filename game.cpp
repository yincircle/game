#include<stdio.h>
#include<stdlib.h>
 int map[20][20];//�½���ͼ����
 struct food {
	 int foodxpost = 0;
	 int foodypost = 0;
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
 int main() {
	 void print_map(); /*��ӡ*/{
		 int p, q;
		 for (p = 0; p < 21; p++) {
			 for (q = 0; q < 21; q++) {
				 if (map[p][q] == 0/*0����հ�*/) {
					 printf(" ");
				 }
				 else if (map[p][q] == 1/*1������*/) {
					 printf("*");
				 }
				 else if (map[p][q] == 2/*2����ʳ��*/) {
					 printf("#");
				 }
				 else if (map[p][q] == 3/*3����߽�*/) {
					 printf("%");
				 }
			 }
		 }

	 }
  }
