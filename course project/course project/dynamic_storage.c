/*
ֱ��д��������:
int function()
{
	int s;
	scanf(%d,&s);
	return s;
}
1����Ϊ����Ҫ��main�����е��ø������������Դ�Ҳ�Ҫд���������Լ����Ե�ʱ��дmain���������ҵ�ʱ��ֻҪ������ʣ�µ�ʲô����Ҫ
ֻ���Լ��ǿ�ĺ�������д�þ�ok��
2����дע�ͣ����ÿ�ж���ע�ͣ�д����ÿ�д�����������ʲô�ģ�ÿ��������������ʲô��
3����ʱ����������һ�λ�����һ���Լ�д���ĸ������ˡ�
4��������������⼰ʱ������ϣ�������һ�ξ�������á�

---------------------------------------------------------------------------------
�˺�������������̬����ṹ������
��������ṹ

���ԣ�
�����ݶ��룬��ȷ�����OK��


*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node			    //����Ľṹ����
{
	char data;					//�ַ�
	int fru;					//Ȩֵ
	struct node *next;
}node;
void display(node *head)		//������ʾ����
{
	node *p;
	p = head;
	if (!p)
		printf("������Ϊ�գ��޷����\n");
	else
	{
		printf("��������ڵ�ֵΪ:\n");
		while (p)
		{
			printf("%c", p->data);
			printf("%5d", p->fru);
			printf("\n");
			p = p->next;
		}
		printf("\n");
	}
}
node *creat()
{
	node *h = NULL, *q = NULL, *p = NULL;
	int i=1;
	/*printf("��������ڵ����:\n");*/
	FILE *fp = fopen("data.txt", "r");
	if (fp)
	{
		printf("�ļ���ȡ�ɹ�\n");
	}
	else
	{
		printf("�ļ���ȡʧ��\n");
		exit(0);
	}
	h = (node *)malloc(sizeof(node));
	fscanf(fp, "%c %d\n", &h->data, &h->fru);
	p = (node *)malloc(sizeof(node));
	fscanf(fp, "%c %d\n", &p->data, &p->fru);
	h->next = p;
	q = p;
	while (1)
	{
		p = (node *)malloc(sizeof(node));
		if (i == 1)
		{
			q->next = p;
			i++;
		}
		if (fscanf(fp, "%c %d\n", &p->data, &p->fru) >= 0)
		{
			p->next = NULL;
			q->next = p;
			q = p;
		}
		else
		{
			break;
		}
	}
	return h;
}
int main()
{
	node *h;
	h = creat();
	display(h);
}
