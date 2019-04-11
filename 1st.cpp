// 1st.cpp : Defines the entry point for the console application.
//顺序表的插入和删除

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
	printf("你想输入的数字多大的长度,");
	printf ("最大长度为%d\n",max);
	scanf ("%d",&L->len);
	printf("请输入:\n");
	for (i=0;i<L->len;i++)
	{
		scanf("%c",&L->data[i]);
		getchar();
	}	

	//输入插入
	
	printf("请输入你要插入的位置\n");
	scanf("%d",&s);
	getchar();
	printf ("请输入你要插入的字符 \n");
	scanf ("%c",&x);
	getchar();
	Insert(L,s,x);//插入
	//输出
	for(i=0;i<L->len;i++)
		printf ("%c",L->data[i]);
	return 0;
}
int Insert(seq *L,int i , char x)//数据表插入
{
	int j;
	if(L->len>=max)
	{
		printf("表满  无法插入\n");
		return 0;
	}
	if(i<0||i>L->len)
	{
		printf("插入位置不合理\n");
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
	printf("插入完成\n");
	return 1; 


}
