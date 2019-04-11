/*实验四  循环队列的基本操作（2学时）
一、实验目的
    了解循环队列的顺序逻辑结构的定义及基本操作，掌握队列的描述方法、特点及有关概念。
二、实验内容
实现顺序循环队列的基本操作，包括：建立循环队列，元素入队，元素出队等。
    基本要求：
（1）正确判断循环队列队满、队空的情况；
（2）可连续测试任意多个元素的入队、出队操作；
            （3）可实现取队头元素；
（4）任一操作结束后将队列中的内容输出；
    （5）可由用户选择退出程序。
三、实验要点及说明
    队列是一种只允许在表的一端进行插入操作而在另一端进行删除操作的线性表。队列的插入操作通常称为进队或入队，队列的删除操作通常称为退队或出队。表中允许进行插入操作的一端称为队尾，允许进行删除操作的一端称为队头，队头和队尾分别由队头指针q->front和队尾指针q->rear指示。 当队列中没有数据元素时称为空队。解决顺序队列假溢出的方法是采用循环队列，即将队列的首尾相接。当q->rear=q->front时，队列为空；当(q->rear+1)%maxnum=q->front时，队列为满，即牺牲一个数据元素空间作为队满标志。
    可按如下格式定义顺序循环队列结构：
                #define MAX 10      /* 定义顺序循环队列最大元素个数10 */
              /*  typedef struct {
                datatype queue[MAX];   定义顺序循环队列queue 
                  int front ;               定义队头指示器
                  int rear;               定义队尾指示器
    } sequeue;
    模块划分：（1）initiate(sequeue *s)函数：初始化顺序循环队列
             （2）int addqueue (sequeue *s, datatype x)函数：入队操作
             （3）int delqueue (sequeue *s, datatype x)函数：出队操作
             （4）int gettop(sequeue *s )函数：取队头元素
         （5）print( )函数：显示输出*/


#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

#define  max 10

typedef struct 
{
	char data[max];
	int front;
	int rear;
}seq;

void init(seq *q)
{
	//q=(seq*)malloc(sizeof(seq));
	q->front=0;
	q->rear=0;
	printf("success\n");

}

int add(seq *q, char x)
{
	if ((q->rear+1)%max==q->front)
	{
		printf("sequeue is full\n");
	}
	else 
	{
		q->rear=(q->rear+1)%max;
		q->data[q->rear]=x;
	}
	printf("add is succeed!\n");
	return 1;
}

void out(seq *q,char *x)
{
	if (q->front==q->rear)
		printf("queue is empty\n");
	else 
	{
//是先加一 还是先传值	
		q->front=(q->front+1)%max;
         printf("the stack top = %c",q->data[q->front]);
		*x=q->data[q->front];
		
		
	}
}
 int gettop(seq *q,char x)
 {
	 if(q->front==q->rear)
		 printf("queue is empty\n");
	 else 
	 {
		 x=q->data[q->rear];
		 
	 }
	 return 1;
 }
 void print(seq *q)
 {
	 int i,x,num=1;
	 i=q->front;
	 x=q->rear;
     //printf("i=%d x=%d\n",i,x);
	 for (;(i+1)%max!=x;i++)
	 {
		 printf("the %dst is %c",num,q->data[i]);
		 num++;
	 }
 }

 void mune()
 {
	 printf("****************\n");
	 printf("1. 初始化\n");
	 printf("2.入栈\n");
	 printf("3.出栈\n");
	 printf("4.取栈顶\n");
	 printf("5.输出\n");
	 printf("****************\n");
 }



 int main ()
 {
	 int number;
	 char x;
	 seq q;
	 system("color 3f");
	 while(1)
	 {
		  char tt;
		 char *y;
		 y=&tt;
		 mune();
		 printf("please click your choice!\n");
		 scanf("%d",&number);
		 if (number==1)
			 init(&q);
		 if (number==2)
		 {
			 printf("please click your vealue!\n");
			 x=getchar();
			 
			 add(&q, x);
		 }
		 if(number==3)
		 {
			out(&q,y);
			printf("get the bottle vealue is %c\n",*y);
		 }
		 if(number==4)
		 {
			 gettop(&q,*y);
			 printf("output the top vealue is %c\n",y);
		 }
		 if(number==5)
		 {
			 print(&q);
		 }
	 }


	return 0;
 }
