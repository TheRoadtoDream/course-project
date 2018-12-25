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

#include"storage.h"
int count()						//��¼�ļ��ڽڵ����
{
	int count = 0;
	char info;
	int fru;
	FILE *fp = fopen("data.txt", "r");
	while (fscanf(fp, "%c %d\n", &info, &fru) >= 0)
	{
		count++;
	}
	return count;
}

void creat(hufmtree tree[])
{
	int i = 0;
	char info;
	int fru;
	FILE *fp = fopen("data.txt", "r");
	if (fp)
		printf("�ļ��򿪳ɹ�");
	else
	{
		printf("�ļ���ʧ�ܣ������ԣ�");
		exit(0);
	}
	while (fscanf(fp, "%c %d\n", &info, &fru) >= 0)			 //�����ļ�����
	{
		tree[i].ch = info;
		tree[i].weight = fru;
		i++;
	}
}
void huffman(hufmtree tree[],int new_m,int new_n)//������������
{
	int i, j, p1, p2;						//p1,p2�ֱ��סÿ�κϲ�ʱȨֵ��С�ʹ�С�������������±�
	int count;
	int small1, small2, f;
	char c;
	creat(tree);
	for (i = 0; i < new_m; i++)			 //��ʼ��
	{
		tree[i].parent = 0;
		tree[i].lchild = -1;
		tree[i].rchild = -1;
		tree[i].weight = 0;
	}
	for (i = new_n; i < new_m; i++)				 //����new_n-1�κϲ�������new_n-1���½��
	{
		p1 = 0; p2 = 0;
		small1 = maxval; small2 = maxval;		 //maxval��float���͵����ֵ
		for (j = 0; j < i; j++)					 //ѡ������Ȩֵ��С�ĸ����
			if (tree[j].parent == 0)
				if (tree[j].weight < small1)
				{
					small2 = small1;		 //�ı���СȨ����СȨ����Ӧ��λ��
					small1 = tree[j].weight;
					p2 = p1;
					p1 = j;
				}
				else
					if (tree[j].weight < small2)
					{
						small2 = tree[j].weight;		 //�ı��СȨ��λ��
						p2 = j;
					}
		tree[p1].parent = i;
		tree[p2].parent = i;
		tree[i].lchild = p1;				//��СȨ��������½�������
		tree[i].rchild = p2;				//��СȨ��������½����Һ���
		tree[i].weight = tree[p1].weight + tree[p2].weight;
	}
}
void huffmancode(codetype code[], hufmtree tree[],int new_m,int new_n)//���ݹ��������������������
//codetype code[]Ϊ����Ĺ���������
//hufmtree tree[]Ϊ��֪�Ĺ�������
{
	int i, c, p;
	codetype cd;
	for (i = 0; i < new_n; i++)
	{
		cd.start = new_n;
		cd.ch = tree[i].ch;
		c = i;						//��Ҷ���������ϻ���
		p = tree[i].parent;			//tree[p]��tree[i]��˫��
		while (p != 0)
		{
			cd.start--;
			if (tree[p].lchild == c)
				cd.bits[cd.start] = '0';		 //tree[i]�������������ɴ���'0'
			else
				cd.bits[cd.start] = '1';		 //tree[i]�������������ɴ���'1'
			c = p;
			p = tree[p].parent;
		}
		code[i] = cd;							//��i+1���ַ��ı������code[i]
	}
}
