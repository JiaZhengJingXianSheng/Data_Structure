// 1st.cpp : Defines the entry point for the console application.
//˳���Ĳ����ɾ��

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#define max 100
typedef struct
{
	char data[max];
	int len;
}seq;
int Insert(seq *L,int i , char x);

int main()
{
	seq *L;
	L=(seq*)malloc(sizeof(seq));
	L->len=0;

	int i;
	int s;
	char x;
	printf("������������ֶ��ĳ���,");
	printf ("��󳤶�Ϊ%d\n",max);
	scanf ("%d",&L->len);
	printf("������:\n");
	for (i=0;i<L->len;i++)
	{
		scanf("%c",&L->data[i]);
		getchar();
	}	

	//�������
	
	printf("��������Ҫ�����λ��\n");
	scanf("%d",&s);
	getchar();
	printf ("��������Ҫ������ַ� \n");
	scanf ("%c",&x);
	getchar();
	Insert(L,s,x);//����
	//���
	for(i=0;i<L->len;i++)
		printf ("%c",L->data[i]);
	return 0;
}
int Insert(seq *L,int i , char x)//���ݱ����
{
	int j;
	if(L->len>=max)
	{
		printf("����  �޷�����\n");
		return 0;
	}
	if(i<0||i>L->len)
	{
		printf("����λ�ò�����\n");
		return 0;
	}
	else
		{  if (i==L->len)
				L->data[i]=x;
			else 
			{   for ( j=L->len-1; j>i; j--)
					L->data[j]=L->data[j];
				L->data[j]=x; 
			}
			L->len++;
		}
	printf("�������\n");
	return 1; 


}
