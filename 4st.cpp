/*ʵ����  ѭ�����еĻ���������2ѧʱ��
һ��ʵ��Ŀ��
    �˽�ѭ�����е�˳���߼��ṹ�Ķ��弰�������������ն��е������������ص㼰�йظ��
����ʵ������
ʵ��˳��ѭ�����еĻ�������������������ѭ�����У�Ԫ����ӣ�Ԫ�س��ӵȡ�
    ����Ҫ��
��1����ȷ�ж�ѭ�����ж������ӿյ������
��2������������������Ԫ�ص���ӡ����Ӳ�����
            ��3����ʵ��ȡ��ͷԪ�أ�
��4����һ���������󽫶����е����������
    ��5�������û�ѡ���˳�����
����ʵ��Ҫ�㼰˵��
    ������һ��ֻ�����ڱ��һ�˽��в������������һ�˽���ɾ�����������Ա����еĲ������ͨ����Ϊ���ӻ���ӣ����е�ɾ������ͨ����Ϊ�˶ӻ���ӡ�����������в��������һ�˳�Ϊ��β���������ɾ��������һ�˳�Ϊ��ͷ����ͷ�Ͷ�β�ֱ��ɶ�ͷָ��q->front�Ͷ�βָ��q->rearָʾ�� ��������û������Ԫ��ʱ��Ϊ�նӡ����˳����м�����ķ����ǲ���ѭ�����У��������е���β��ӡ���q->rear=q->frontʱ������Ϊ�գ���(q->rear+1)%maxnum=q->frontʱ������Ϊ����������һ������Ԫ�ؿռ���Ϊ������־��
    �ɰ����¸�ʽ����˳��ѭ�����нṹ��
                #define MAX 10      /* ����˳��ѭ���������Ԫ�ظ���10 */
              /*  typedef struct {
                datatype queue[MAX];   ����˳��ѭ������queue 
                  int front ;               �����ͷָʾ��
                  int rear;               �����βָʾ��
    } sequeue;
    ģ�黮�֣���1��initiate(sequeue *s)��������ʼ��˳��ѭ������
             ��2��int addqueue (sequeue *s, datatype x)��������Ӳ���
             ��3��int delqueue (sequeue *s, datatype x)���������Ӳ���
             ��4��int gettop(sequeue *s )������ȡ��ͷԪ��
         ��5��print( )��������ʾ���*/


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
//���ȼ�һ �����ȴ�ֵ	
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
	 printf("1. ��ʼ��\n");
	 printf("2.��ջ\n");
	 printf("3.��ջ\n");
	 printf("4.ȡջ��\n");
	 printf("5.���\n");
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
