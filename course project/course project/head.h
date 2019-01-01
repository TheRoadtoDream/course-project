#pragma once
/*
���ļ��а����˸ó����������п��ļ��Լ����к�����
*/
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�����ͷ�ļ���������ͼ�λ���������
#include <conio.h>			// ����ͼ�ο�ͷ�ļ�����ͷ�ļ�����ͼ�λ�������ơ�

typedef struct node
{
	char info;				//�����ַ�
	int data;				//����Ȩֵ
	char encode[20];		//������������
	node *lchild, *rchild, *next,* parent;			//�����������������������next���壬
	//��������ĺô���ֻ��Ҫ����һ�νṹ�����������ʵ�����ṹ������ṹ��ͨ�ã����ٴ�������
}hufnode;
typedef struct stack					//ջ�ṹ���壬�˽ṹ������������������ɵĹ��������롣
{
	int data[100];
	int top;
}stack_1;

void QuickSort(hufnode y[], int left, int right);		//����Ԫ�ؿ�������
hufnode *tolink(hufnode a[], int count);				//������������Ԫ��������������
int readdata(hufnode x[]);								//���ļ���ȡ����
hufnode *insert(hufnode * root, hufnode *s);			//ȡ����С�ڵ㽫�ڵ����
hufnode *creathuff(hufnode * root);						// ���ɹ��������Ĵ�������

void treeencode(hufnode *t,hufnode *h,int count);		//�ù������������б���
void decode(hufnode tree[]);							//���ù������������н���

void init(stack *s);						//ջ��ʼ��	
void push(stack *s, int  a);				//ѹջ
int pop(stack *s);							//��ջ
void draw(int x, int y, char c);			//�����
void drawdemo(hufnode *s, int x, int y);	//������������
void draw_main(hufnode *s);					//ͼ�λ�����������