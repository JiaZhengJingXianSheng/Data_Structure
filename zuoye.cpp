/*
һ������ջstack��m���Ӽ�����������  �������������������ջ
����ż�� ������ջ��ֱ��ջ��
*/
#define max 10
#include "stdio.h"
#include "stdlib.h" 
typedef struct
{
	int data[max];
	int top;
	int flag;
}seqstack;
void init_seqstack(seqstack**s)//chushihuazhan
{
	*s = (seqstack*)malloc(sizeof(seqstack));
	(*s)->top = -1;
	(*s)->flag = max;
}
int test(seqstack*x)
{
	if ((x->top) + (max - (x->flag)) >= (max - 1))
	{
		printf("The stack is full\n");
		int y=0;
		printf("This is real option  your input\n");
		while(y<max)
		{
			printf("%d\n",x->data[y]);
			y++;
		}
	}
	return 1;
}

int main()
{
	seqstack *p;
	init_seqstack(&p);
	printf("please input the data (only int datatype)\n");
	int x,y=1;
	
	while (y == 1)
	{
		scanf("%d", &x);
		test(p);
		if (x % 2 == 0)
		{
			p->top++;
			p->data[p->top] = x;
		}
		if (x % 2 == 1)
		{
			p->flag--;
			p->data[p->flag] = x;
		}
		y = test(p);
	}
	
	
	return 2;
}
