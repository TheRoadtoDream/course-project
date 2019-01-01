/*


---------------------------------------------------------------------------------
���ļ��������б���ͼ�λ��������
---------------------------------------------------------------------------------

*/

#include"head.h"					//������ͷ�ļ�
void  draw_main(hufnode *s)
{
	int tmp = 100;
	int suojian = 1;
	initgraph(1920, 1080);			// ������ͼ���ڣ�SHOWCONSOLE
	setbkcolor(WHITE);				// ���ñ��������ɫ
	cleardevice();					//�������
	setcolor(RED);
	drawdemo(s,860,20);				//�ݹ���û��������ļ�
	_getch();						 // ����������ʱ�䡣
	closegraph();					 // �رջ�ͼ����

}
int temp = 1000;
int suojian = 4;

void draw(int x, int y, char c) 
{
	circle(x, y, 20); Sleep(100);//��Ȧ����ͣ100ms
	outtextxy(x - 5, y - 5, c);   //���Ԫ��
}


void drawdemo(hufnode *s, int x, int y) 
{
	if (s != NULL)
		draw(x, y, s->info);
	if (s->lchild != NULL) 
	{
		suojian+=4;//����ֵ����
		line(x - 14, y + 14, x - temp / suojian, y + 50 - 20); Sleep(100);//���߲���ͣ100ms
		drawdemo(s->lchild, x - temp / suojian, y + 50);//�ݹ����������
	}
	if (s->rchild != NULL) 
	{
		suojian+=4;//����ֵ����
		line(x + 14, y + 14, x + temp / suojian, y + 50 - 20); Sleep(100);//���߲���ͣ100ms
		drawdemo(s->rchild, x + temp / suojian, y + 50);//�ݹ����������
	}
	suojian-=4;
}//�����ĵݹ��㷨

/*
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>

void menu();
int check_button(int,int);
void button1(MOUSEMSG,int,int,int,int);
void button2(MOUSEMSG,int,int,int,int);

/*struct MOUSEMSG
{
	UINT uMsg;      // ��ǰ�����Ϣ
	bool mkCtrl;    // Ctrl ���Ƿ���
	bool mkShift;   // Shift ���Ƿ���
	bool mkLButton; // �������Ƿ���
	bool mkMButton; // ����м��Ƿ���
	bool mkRButton; // ����Ҽ��Ƿ���
	int x;          // ��ǰ��� x ����
	int y;          // ��ǰ��� y ����
	int wheel;      // �����ֹ���ֵ
};

typedef struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
}btnode; //���Ľṹ��

int temp;  //����������ȵõ���ʼ����ֵ
int suojian = 1;  //����������ʱ����������
btnode *t;      //���ĸ��ڵ�


btnode *create(char *pre, char *in, int n) {
	btnode *s;    //��ǰ�ڵ�
	char *p;      //�������ݵ�ָ��
	int k;        //��¼λ��
	if (n <= 0) return NULL;   //�����ǰ�ݹ���û�����ݣ����ؿ�ָ��
	s = (btnode *)malloc(sizeof(btnode));   //Ϊ��ǰ�ڵ�����ڴ�ռ�
	s->data = *pre;                         //��ǰ�ڵ㸳ֵ���������е���ֵ��
	for (p = in; p < in + n; p++)
		if (*p == *pre)
			break;                            //����p��λ��
	k = p - in;
	s->lchild = create(pre + 1, in, k);         //������ǰ����������
	s->rchild = create(pre + k + 1, p + 1, n - k - 1);  //������ǰ����������
	return s;                             //���ص�ǰ�ڵ�
}//������������򴴽�������

btnode *getree(btnode *s, char *str) {
	btnode *p[50], *n = NULL;
	int top = -1, j = 0, k;
	char ch;
	s = NULL;
	while ((ch = str[j++]) != '\0') {
		switch (ch) {
		case '(':top++; p[top] = n; k = 1; break;
		case ')':top--; break;
		case ',':k = 2; break;
		default:n = (btnode *)malloc(sizeof(btnode));
			n->data = ch; n->lchild = n->rchild = NULL;

			if (s == NULL)
				s = n;
			else {
				switch (k) {
				case 1:p[top]->lchild = n; break;
				case 2:p[top]->rchild = n; break;
				}
			}
		}
	}
	return s;
}                              //������


int deep(btnode *s) {
	int dl, dr;
	if (s == NULL) return 0;
	else {
		dl = deep(s->lchild);
		dr = deep(s->rchild);
		return (dl > dr) ? (dl + 1) : (dr + 1);
	}
}//���������

void draw(int x, int y, char c) {
	circle(x, y, 20); Sleep(100);//��Ȧ����ͣ100ms
	outtextxy(x - 5, y - 5, c);   //���Ԫ��
}


void print(btnode *s, int x, int y) {
	if (s != NULL)
		draw(x, y, s->data);
	if (s->lchild != NULL) {
		suojian++;//����ֵ����1
		line(x - 14, y + 14, x - temp / suojian, y + 100 - 20); Sleep(100);//���߲���ͣ100ms
		print(s->lchild, x - temp / suojian, y + 100);//�ݹ����������
	}
	if (s->rchild != NULL) {
		suojian++;//����ֵ����1
		line(x + 14, y + 14, x + temp / suojian, y + 100 - 20); Sleep(100);//���߲���ͣ100ms
		print(s->rchild, x + temp / suojian, y + 100);//�ݹ����������
	}
	suojian--;
}//�����ĵݹ��㷨


void main() {
	IMAGE img;
	initgraph(1000, 700);        //����ͼ�δ���
	setfillcolor(RED);       //�������ɫ
	setbkcolor(WHITE);         //���ñ���ɫ
	settextcolor(GREEN);       //�����ı���ɫ
	setcolor(BLACK);           //���ߵ���ɫ
	setbkmode(TRANSPARENT);    //͸�����
	print(t, 500, 100);            //�������������ڵ㣬���ڵ�x���꣬���ڵ�y���꣩
	getch();                     //��ͣ
}

void menu() {
	MOUSEMSG m;              //������
	IMAGE img;
	bar3d(400, 200, 600, 250, 2, true);        //��ʵ����
	outtextxy(420, 220, "����������򻭶�����");   //ʵ�����е�����
	bar3d(400, 260, 600, 310, 2, true);
	outtextxy(420, 280, "��������������");
	while (1) {
		m = GetMouseMsg();                          //�ȴ�����¼�
		if (m.uMsg == WM_LBUTTONDOWN)   //�����������ʱbreak
			if (check_button(m.x, m.y) == 1)
			{
				button1(m, 400, 200, 600, 250); break;
			}
			else if (check_button(m.x, m.y) == 2)
			{
				button2(m, 400, 260, 600, 310); break;
			}
	}
	cleardevice();	                       //���ͼ�ν�������
	loadimage(&img, "IMAGE", "back");
	putimage(0, 0, &img);
	setlinestyle(0, 2, NULL);
}


int check_button(int x, int y) {
	if (x > 400 && x < 600 && y>200 && y < 250)
		return 1;
	else if (x > 400 && x < 600 && y>260 && y < 310)
		return 2;
}                                     //�����갴��ʱ��λ��

void button1(MOUSEMSG m, int x1, int y1, int x2, int y2) {
	int dis = 1;
	char xianxu[20], zhongxu[20];     //�������к���������
	int n, high;                //nΪ���г��ȣ�highΪ���ĸ߶�
	line(x1 + dis, y1 + dis, x2 - dis, y1 + dis);
	line(x2 - dis, y1 + dis, x2 - dis, y2 - dis);
	line(x2 - dis, y2 - dis, x1 + dis, y2 - dis);
	line(x1 + dis, y2 - dis, x1 + dis, y1 + dis);
	Sleep(200);
	//xianxu="ABDGLMHEIKCFJ";
	//zhongxu="MLGDHBEKIACJF";   //Ϊ��ǰ���и�ֵ
	InputBox(xianxu, 20, "�������������У�");
	InputBox(zhongxu, 20, "�������������У�");
	n = strlen(xianxu);          //n������г���
	t = create(xianxu, zhongxu, n);   //����������
	high = deep(t);
	high--;                      //��õ�ǰ�߶ȼ�1
	temp = 1000 / high;              //��ó�ʼ����ֵ

}                                        //��һ������

void button2(MOUSEMSG m, int x1, int y1, int x2, int y2) {
	int dis = 1;
	char str[20];
	line(x1 + dis, y1 + dis, x2 - dis, y1 + dis);
	line(x2 - dis, y1 + dis, x2 - dis, y2 - dis);
	line(x2 - dis, y2 - dis, x1 + dis, y2 - dis);
	line(x1 + dis, y2 - dis, x1 + dis, y1 + dis);
	Sleep(200);
	//str="A(B(D(,G)),C(E,F))";  //Ϊ��ǰ����ֵ
	InputBox(str, 20, "�����������磺A(B(D(,G)),C(E,F))");
	temp = 200;
	t = getree(t, str);
}
*/
