/*一、实验目的
了解链表的逻辑结构特征，掌握链表的描述方法、特点及有关概念，掌握链表的建立、插入、删除以及查找的基本操作算法。
二、实验内容
实现单链表的基本操作，包括：建立单链表，插入结点，删除结点，查找结点，打印输出单链表中的所有结点。
基本要求：
（1）初始化单链表；
（2）程序具有单链表插入、删除和显示功能，可根据用户需要连续操作（插入位置、插入结点的数据及被删除结点的数据要从键盘输入）；
            （3）根据键盘输入的数据在单链表中查找结点；
（4）任一操作结束后将单链表中的内容输出；
（5）可由用户选择退出程序。
三、实验要点及说明
线性表的链式存储结构是一种物理存储单元上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接的次序实现的。线性表的链式存储结构中只有一个指针域的链表称为单链表。
    可按如下格式定义单链表的结点结构：
                typedef struct node
                  { datatype data;         /*结点数据域
                    struct node *next;      结点指针域  
} slnode；
划分各功能模块：
（1）initiate(slnode **h)函数：初始化单链表
（2）int  Creat1(slnode * h, int n)函数：建立单链表
    （3）insert(slnode *h ,int i , datatype  x)函数：在带头结点的单链表h中第i个位置前插入新结点x。
（4）delete(slnode *h ,int i)函数：删除第i个位置的结点
    （5）search(slnode *h ,int i )函数：查找第i个位置结点的值。
    （6）print(slnode *h )函数：显示输出单链表中的所有结点。
*/


#include "stdlib.h"
#include "stdio.h"
void choice();
typedef struct node
{
	char data;
	struct node *next;
}LNode;
int initiate (LNode **head);
int Creat (LNode *head);
int  insert (LNode *head, int i,char x);/* i 插入结点的位置*//* x 插入结点的数据*/

int main ()
{	
	system("color F3");
	int x,y,z;//x为菜单选择 y为插入 z为删除
	char w;//w为插入字符
	LNode *head,*s;
	while(1)
	{
		
		choice();
		printf("please input you choice number\n");
		scanf ("%d",&x);
		if(x==1)
		{
			initiate (&head);
		//	Creat (&&head);
		}
		else if(x==2)
		{
			printf("please input your insert-number\n");
			scanf("%d",&y);
			printf("please input your insert-vaule\n");
			scanf("%c",&w);
			insert (head, y,z);
		}
	}
	return 0;
}

void choice()//
{
	printf("please choose your choice.\n");
	printf("1.初始化\n");
	printf("2.插入\n");
	printf("3.删除\n");
	printf("4.显示\n");
	printf("5.退出\n");
}



/*初始化*/
int initiate (LNode **head)
{ 
	*head=( LNode * )malloc(sizeof(LNode));
	if (*head==NULL) 
	{   printf("初始化失败！\n");
		return 0;  }
	(*head)->next=NULL;
	printf("完成初始化 !\n");
	return 1;
}
/*建立单链表*/
int Creat (LNode *head)
{  
	LNode *p,*q;
	int n,i;         /* n 单链表中最初的结点数*/
	char a[10];       /* a 单链表中最初的数据*/
	if(head==NULL)
	{   printf("单链表未初始化！\n");
		return 0;  }
	printf("请输入单链表最初的结点数n=");
	scanf("%d",&n);
	printf("请输入各个结点数据域的值:");
	for(i=0;i<n;i++)
	{   scanf("%c",&a[i]); 
		getchar();
	}
	p=head;
	while (p->next!=NULL)
		p=p->next;
	for(i=0;i<=n-1;i++)
	{   if ((q=( LNode * )malloc(sizeof(LNode)))==NULL)
		{  
			printf("新结点空间申请失败！\n");
			return 0;  
		}
		q->data=a[i];
		q->next=NULL;
		p->next=q;
		p=q;   
	}
	return 1;   
}
/*插入*/
int  insert (LNode *head, int i,char x)/* i 插入结点的位置*//* x 插入结点的数据*/
{  
	LNode *p, *q;
	int  j=0;              	          
	p=head;               
   	while((p->next!=NULL)&&(j<i-1))
		{   
			p=p->next;
			j++;   
		}
		if(j!=i-1)
		{
			printf("\n插入位置不合理！\n"); 
			return 0;  }
		else
		{   if ((q=( LNode * )malloc(sizeof(LNode)))==NULL)
			{	printf("新结点空间申请失败！\n");
				return 0;   
			}
			q->data=x;
			q->next=p->next;
			p->next=q;
		}  
	printf("插入完成!\n");
	return 1;  
 }
