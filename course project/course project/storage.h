#pragma once

#include<stdio.h>
#include<stdlib.h>
#define n 100				 //Ҷ�������Ŀ
#define m (2*n-1)			//���������(2*n-1)
#define maxval 10000.0
#define maxsize 100			//��������������λ��
//static n;
typedef struct
{
	char ch;
	int weight;
	int lchild, rchild, parent;
}hufmtree;
typedef struct codetype
{
	char bits[n];			 //λ��
	int start;				 //������λ���е���ʼλ��
	char ch;				 //�ַ�
}codetype;		

void huffman(hufmtree tree[],int new_m,int new_n);	//������������
void huffmancode(codetype code[], hufmtree tree[],int new_m, int new_n);	//���ݹ��������������������
void decode(hufmtree tree[], int new_m);	//���ζ��룬���ݹ�����������
int count();	//��¼�ļ��ڵ����