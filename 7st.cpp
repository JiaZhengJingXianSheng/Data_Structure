/*实验七  顺序查找和二分查找（2学时）
一、实验目的
　　掌握顺序查找和二分查找的基本思想，查找过程及其实现的算法。
二、实验内容
对已知关键字序列分别进行顺序查找和二分查找。
　　基本要求：
　　        （1）给定关键字序列通过键盘任意输入；
　　        （2）查找方式可由用户选择；
　　        （3）输出查找记录的位置；
            （4）可由用户选择退出程序。
三、实验要点及说明
　　顺序查找是一种简单的查找方法，数据记录顺序存放在某顺序表中。顺序表查找的方法是：从顺序表的一端开始，用给定值逐个顺序地与表中各记录的关键字相比较，如在表中找到某个记录的关键字与给定值相等，表明查找成功；
　　二分查找又称二分查找，它要求待查找的顺序表必须是有序表，即表中各记录按其关键字值的大小顺序存储。
可按如下格式定义记录的结构：
                  typedef  struct  
                 {int  key;
                  Char data;
             }datatype;
　　模块划分：（1）getsort( )函数：输入记录的关键字
         （2）seqsearch ( )函数：顺序查找
         （3）binsearch( )函数：二分查找
         （4）insertsort( )函数：直接插入排序
         （5）print( )函数：显示输出*/
#include <stdio.h>
#define MAXLEN 50
typedef  struct {
	int key;
	char data;
}datatype;
int getsort(datatype x[] );
int seqsearch(datatype x[],int key,int n);
int binsearch(datatype x[],int key,int n );
void insertsort(datatype x[],int n);
void print(datatype x[],int n);
void main()
{   int sel,n,s,key,i;   /*sel 输入选择，n 记录长度，s 查找方法的选择，key 查找关键字给定值，i 目标记录的下标*/
	datatype x[MAXLEN];
	printf("请输入你的选择：1---开始 其他选择为退出 \nyour choice =");
	scanf("%d",&sel);
	while(sel==1)
	{   printf("\n输入关键字序列，以－1结束输入：");
		n=getsort(x );
		printf("请输入选择的查找方法：1---顺序查找 2---二分查找 3-退出查找\nyour choice =");
		scanf("%d",&s);
		while(s!=3)
		{   printf("请输入查找关键字给定值key＝");
			scanf("%d",&key);
			if(s==1)
			{   printf("\n原关键字序列为：");
				print(x,n);
				i=seqsearch(x,key,n);
				if(i==-1)
					printf("\n没有给定值记录！\n");
				else
					printf("\n查找的结果为表中的第 %d 条记录!\n",i+1);  }
			else if(s==2)
			{   i= binsearch(x,key,n );
				if(i==-1)
					printf("\n没有给定值记录！\n");
				else
					printf("\n查找的结果为表中的第 %d 条记录!\n",i+1);   }
			else
				printf("选择错误！\n");
			printf("请输入选择的查找方法：1---顺序查找 2---二分查找 3-退出查找\nyour choice =");
			scanf("%d",&s);   }
		printf("请输入你的选择：1---开始 其他选择为退出 \nyour choice =");
		scanf("%d",&sel);  }  }
/*输入记录的关键字*/
int getsort(datatype x[] )
{   int i=0;
	scanf("%d",&x[i].key);
	while(x[i].key!=-1)
	{   i++;
		scanf("%d",&x[i].key);  }
	return i;  }
/*顺序查找*/
int seqsearch(datatype x[],int key,int n)
{   int i;
	for(i=0;i<n;i++)
	{   if(key==x[i].key)
			return i;  }
	return -1;  }
/*二分查找*/
int binsearch(datatype x[],int key, int n)
{   int low,mid,hig;                /*定义位置指示器*/
	datatype y[MAXLEN];
	low=0;
	hig=n-1;
	for(int i=0;i<n;i++)
		y[i]=x[i];
	insertsort(y,n);                   /*排序*/
	printf("\n排序后关键字序列为：");
	print(y,n);
	while(low<=hig)                 /*查找*/
	{   mid=(low+hig)/2;
		if(key ==y[mid].key)
			return mid;
		else if(key >y[mid].key)
			low=mid+1;
		else
			hig=mid-1;  }
	return -1;  }
/*直接插入排序*/
void insertsort(datatype x[],int n)
{   int i,j;
	datatype temp;          /*中间变量*/
	for(i=1;i<n;i++)
	{   temp=x[i];
		j=i-1;
		while(j>-1 && temp.key<x[j].key)
		{   x[j+1]=x[j];
			j--;  }
		x[j+1]=temp;  }  }
/*显示输出*/
void print(datatype x[],int n)
{   int i;
	for(i=0;i<n;i++)
		printf("%d\t",x[i]);
	printf("\n");   }