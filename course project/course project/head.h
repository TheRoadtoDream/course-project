#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�����ͷ�ļ���������ͼ�λ���������
#include <conio.h>			// ����ͼ�ο�ͷ�ļ�����ͷ�ļ�����ͼ�λ�������ơ�

typedef struct node
{
	char info;				//�����ַ�
	int data;				//����Ȩֵ
	node *lchild, *rchild, *next;
}hufnode;

void QuickSort(hufnode y[], int left, int right);//����Ԫ�ؿ�������
hufnode *tolink(hufnode a[], int count);				//������������Ԫ��������������
int readdata(hufnode x[]);							//���ļ���ȡ����
hufnode *insert(hufnode * root, hufnode *s);					//ȡ����С�ڵ㽫�ڵ����
hufnode *creathuff(hufnode * root);								// ���ɹ��������Ĵ�������
void ppt();
void inorder(hufnode *t);