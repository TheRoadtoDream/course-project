#include"storage.h"
void decode(hufmtree tree[],int new_m)			//���ζ��룬���ݹ�����������
{
	int i, j = 0;
	char b[maxsize];
	char endflag = '2';					//������־ȡ2
	i = new_m - 1;					 //�Ӹ���㿪ʼ��������
	printf("�������(��'2'Ϊ������־)��");
	gets(b);
	printf("�������ַ�Ϊ:\n");
	while (b[j] != '2')
	{
		if (b[j] == '0')
			i = tree[i].lchild;				//��������
		else
			i = tree[i].rchild;				//�����Һ���
		if (tree[i].lchild == -1)			 //tree[i]��Ҷ���
		{	
			printf("%c", tree[i].ch);
			i = new_m - 1;						//�ص������
		}
		j++;
	}
	printf("\n");
	if (tree[i].lchild != -1 && b[j] != '2')			//���꣬����δ��Ҷ�ӽ��
		printf("\n������ĵ����д�����������!\n");		//��������д�
}