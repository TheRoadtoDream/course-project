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
���ļ��������б������
---------------------------------------------------------------------------------
*/
#include"dynamic_storage.c"
//int  functionbianma(node *head )/*������뺯��*/
//{
//	int code[10];
//	int n;
//	if (head)
//	{
//		if (head->lchid == NULL && head->rchild == NULL)
//			printf("idΪ%cȨֵΪ%d��Ҷ�ӽڵ�Ĺ���������Ϊ��",head->data, head->fru);
//		int i;
//		for (i = 0; i <= n; i++)
//		{
//			printf("%d", code[i]);
//		}
//		printf("\n");
//	}
//	else
//	{
//		code[n] = 0;
//		functionbianma(head->lchild, n + 1);
//		code[n] = 1;
//		functionbianma(head->rchild, n + 1);
//
//	}
//}
//int display(node *head)
//{
//	if (head)
//	{
//		display(head->lchild);
//		printf("idΪ%c��Ҷ�ӽڵ��ȨֵΪ%d",head->data, head->fru);
//		display(head->rchild);
//
//	}
//}