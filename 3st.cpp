/*����ʵ������
ʵ��˳���ջ�Ļ�����������������ʼ����ջ����ջ����ջ��ȡջ��Ԫ�ء�
����Ҫ��
��1��˳���ջ��Ԫ�ظ����������趨��
��2������������������Ԫ�صĽ�ջ����ջ������
            ��3����ʵ��ȡջ��Ԫ�أ�
��4����һ����������˳���ջ�е����������
��5�������û�ѡ���˳�����
����ʵ��Ҫ�㼰˵��
ջ���߼��ṹ�����Ա���ͬ����������������Ա�������˸�������ƣ�
���ֳƲ������޵����Ա�ջ��һ��ֻ�����ڱ��һ�˽��в����ɾ�����������Ա�
ֻ������룬ɾ��������һ�˳�Ϊջ������һ�˳�Ϊջ�ף�
ջ����ǰλ������һ��ջ��ָʾ��ָʾ�����������Ϊ��ջ����ջ��ɾ��������Ϊ��ջ����ջ��
��ջ��û���κ�Ԫ��ʱ��Ϊ��ջ��
    �ɰ����¸�ʽ�����ջ��˳��洢�ṹ��
                #define MAX  10      /* ����˳���ջ���Ԫ�ظ���*/
//*typedef struct
//{
//	datatype stack[MAX];   * ����˳���ջstack */
//	int top;   */           /* ����ջ��ָʾ��*/*
//}seqstack;
/*ģ�黮�֣���1��initiate()��������ʼ��˳���ջ
��2��push()��������ջ����
��3��pop()��������ջ����
��4��stacktop()������ȡջ��Ԫ��
��5��print()��������ʾ���ջ��Ԫ��
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
	//char ����ȡֵ
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
	//char ����ȡֵ
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
	printf("1. ��ʼ��\n");
	printf("2. ��ջ����\n");
	printf("3. ��ջ����\n");
	printf("4. ȡջ��\n");
	printf("5. ���\n");
	printf("****************\n");

}
int main()
{

	system("color 3f");
	int insert_number;
	seqstack s;
//	s=(seqstack*)malloc(sizeof(seqstack));
	char x;//��ջ�ַ�
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