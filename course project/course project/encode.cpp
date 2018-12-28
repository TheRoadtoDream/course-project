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
*/

#include"head.h"
hufnode *insert(hufnode * root, hufnode *s)					//ȡ����С�ڵ㽫�ڵ����
{
	hufnode *p1, *p2;
	if (root == NULL)
		root = s;
	else
	{
		p1 = NULL;
		p2 = root;
		while (p2&&p2->data < s->data)
		{
			p1 = p2;
			p2 = p2->next;
		}
		s->next = p2;
		if (p1 == NULL)
			root = s;
		else
			p1->next = s;
	}
	return root;
}
hufnode *creathuff(hufnode * root)								// ���ɹ��������Ĵ�������
{
	hufnode *s, *rl, *rr;
	while (root&&root->next)
	{
		rl = root;
		rr = root->next;
		root = rr->next;
		s = (hufnode *)malloc(sizeof(hufnode));
		s->info = NULL;
		s->next = NULL;
		s->data = rl->data + rr->data;
		s->lchild = rl;
		s->rchild = rr;
		rl->next = rr->next = NULL;
		root = insert(root, s);						//ͨ����β���ʵ��
	}
	printf("������ɣ�\n");
	return root;
}
int readdata(hufnode x[])							//���ļ���ȡ����
{
	char ch;
	int fru;
	FILE *fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		return 0;
	}
	int i = 0;
	while (fscanf(fp, "%c %d\n", &ch, &fru) >= 0)
	{
		x[i].info = ch;
		x[i].data = fru;
		i++;
	}
	/*for (int j = 0; j < i; j++)
	{
		printf("%c %d\n", x[j].info, x[j].data);
	}
	printf("��ȡ�ɹ���\n");*/
	return i;
}
void QuickSort(hufnode y[], int left, int right)				//���ṹ�������������
{
	hufnode x;
	int i, j, flag = 1;
	if (left < right)
	{
		i = left;
		j = right;
		x = y[i];
		while (i < j)
		{
			while (i < j&&x.data < y[j].data)
				j--;
			if (i < j)
				y[i++] = y[j];
			while (i < j&&x.data > y[i].data)
				i++;
			if (i < j)
				y[j--] = y[i];
		}
		y[i] = x;
		QuickSort(y, left, i - 1);		//�ݹ�ʵ�ַ��� 
		QuickSort(y, i + 1, right);
	}
}
hufnode *tolink(hufnode a[], int count)				//������������Ԫ��������������
{
	node *h = NULL, *q = NULL, *p = NULL;
	int  i;
	for (i = 0; i < count; i++)
	{
		p = (node *)malloc(sizeof(node));
		p->info = a[i].info;
		p->data = a[i].data;
		p->lchild = NULL;
		p->rchild = NULL;
		p->next = NULL;
		if (i == 0)
		{
			h = p; q = p;
		}
		else
		{
			q->next = p; q = p;
		}
	}
	return h;
}

void treeencode(hufnode *t)
{
	stack s;
	queue q;
	q.front = 0;
	q.rear = 0;
	int flag=0;
	int i = 0;
	init(&s);
	while (t != NULL || s.top != 0)
	{
		if (t)
		{
			push(&s, *t);
			if (t->lchild == NULL && t->rchild == NULL)
			{
				for (i = 0; i < q.rear; i++)
				{
					t->encode[i] = q.data[i];
				}
				t->encode[i] = 2;
				if (t->info != NULL)
				{
					printf("%c ", t->info);
					for (i = 0; t->encode[i] != 2; i++)
					{
						printf("%d", t->encode[i]);
					}
				}
				printf("\n");
			}
			if (flag == 0 )
				q.data[q.rear++] = 0;
			if (flag == 1 )
				q.data[q.rear++] = 1;
			t = t->lchild;
			flag = 0;
		}
		else 
		{
			t = pop(&s);
			q.rear--;
			t = t->rchild;
			flag = 1;
		}
	}
}
void init(stack *s)
{
	s->top = 0;
}
void push(stack *s, hufnode a)
{
	s->data[s->top++] = a;
}
hufnode *pop(stack *s)
{
	s->top--;
	return(&s->data[s->top]);
}