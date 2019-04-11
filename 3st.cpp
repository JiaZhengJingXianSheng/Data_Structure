/*二、实验内容
实现顺序堆栈的基本操作，包括：初始化堆栈，进栈，出栈，取栈顶元素。
基本要求：
（1）顺序堆栈的元素个数可随意设定；
（2）可连续测试任意多个元素的进栈、出栈操作；
            （3）可实现取栈顶元素；
（4）任一操作结束后将顺序堆栈中的内容输出；
（5）可由用户选择退出程序。
三、实验要点及说明
栈的逻辑结构和线性表相同，但运算规则与线性表相比有了更多的限制，
故又称操作受限的线性表。栈是一种只允许在表的一端进行插入或删除操作的线性表。
只允许插入，删除操作的一端称为栈顶，另一端称为栈底，
栈顶当前位置是由一个栈顶指示器指示；插入操作称为进栈或入栈，删除操作称为出栈或退栈；
当栈中没有任何元素时称为空栈。
    可按如下格式定义堆栈的顺序存储结构：
                #define MAX  10      /* 定义顺序堆栈最大元素个数*/
//*typedef struct
//{
//	datatype stack[MAX];   * 定义顺序堆栈stack */
//	int top;   */           /* 定义栈顶指示器*/*
//}seqstack;
/*模块划分：（1）initiate()函数：初始化顺序堆栈
（2）push()函数：进栈操作
（3）pop()函数：出栈操作
（4）stacktop()函数：取栈顶元素
（5）print()函数：显示输出栈内元素
*/
#include"stdio.h"
#include "stdlib.h"
#include "malloc.h"
#define max 20
typedef struct
{
	char data[max];
	int top;
}seqstack;
void init_seqstack(seqstack*s)
{
	s->top = -1;
}
int push(seqstack*s,char x)
{
	if (s->top==max-1)
	{
		printf("the stack is full\n");
		return 0;
	}
	s->top++;
	s->data[s->top]=x;
	return 1;
}
int pop(seqstack*s)
{
	//char 是所取值
	if (s->top==-1)
	{
		printf("the stack is empty!\n");
		return 2;
	}
	//x=s->data[s->top];
	
	printf("the %dst output stack is %c",s->top,s->data[s->top]);
	s->top--;
	return 1;
}
int stacktop(seqstack*s,char x)
{
	//char 是所取值
	if(s->top==-1)
	{
		printf("the stack is empty!\n");
		return 1;
	}
	x=s->data[s->top];
	return 1;
}
int print(seqstack*s)
{
	int i=0;
	if(s->top==-1)
	{
		printf("the stack is empty\n");
		return 1;
	}
	while(i<s->top)
	{
		printf("the stack[%d] is %c",i+1,s->data[i]);
		i++;
	}
}
void mune ()
{
	printf("****************\n");
	printf("1. 初始化\n");
	printf("2. 进栈操作\n");
	printf("3. 出栈操作\n");
	printf("4. 取栈顶\n");
	printf("5. 输出\n");
	printf("****************\n");

}
int main()
{

	system("color 3f");
	int insert_number;
	seqstack s;
//	s=(seqstack*)malloc(sizeof(seqstack));
	char x;//进栈字符
	while(1)
	{
		mune();
		scanf("%d",&insert_number);
		if(insert_number==1)
		{
			init_seqstack(&s);
		}
		if(insert_number==2)
		{
			printf("please input your data!\n");
			//getchar();
			scanf("%c",&x);
			//getchar();
			push(&s,x);
		}
		if(insert_number==3)
		{
			pop(&s);
		}
	}
	return 0;
}