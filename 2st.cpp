/*һ��ʵ��Ŀ��
�˽�������߼��ṹ��������������������������ص㼰�йظ����������Ľ��������롢ɾ���Լ����ҵĻ��������㷨��
����ʵ������
ʵ�ֵ�����Ļ������������������������������㣬ɾ����㣬���ҽ�㣬��ӡ����������е����н�㡣
����Ҫ��
��1����ʼ��������
��2��������е�������롢ɾ������ʾ���ܣ��ɸ����û���Ҫ��������������λ�á�����������ݼ���ɾ����������Ҫ�Ӽ������룩��
            ��3�����ݼ�������������ڵ������в��ҽ�㣻
��4����һ���������󽫵������е����������
��5�������û�ѡ���˳�����
����ʵ��Ҫ�㼰˵��
���Ա����ʽ�洢�ṹ��һ������洢��Ԫ�Ϸ���������˳��Ĵ洢�ṹ������Ԫ�ص��߼�˳����ͨ�������е�ָ�����ӵĴ���ʵ�ֵġ����Ա����ʽ�洢�ṹ��ֻ��һ��ָ����������Ϊ������
    �ɰ����¸�ʽ���嵥����Ľ��ṹ��
                typedef struct node
                  { datatype data;         /*���������
                    struct node *next;      ���ָ����  
} slnode��
���ָ�����ģ�飺
��1��initiate(slnode **h)��������ʼ��������
��2��int  Creat1(slnode * h, int n)����������������
    ��3��insert(slnode *h ,int i , datatype  x)�������ڴ�ͷ���ĵ�����h�е�i��λ��ǰ�����½��x��
��4��delete(slnode *h ,int i)������ɾ����i��λ�õĽ��
    ��5��search(slnode *h ,int i )���������ҵ�i��λ�ý���ֵ��
    ��6��print(slnode *h )��������ʾ����������е����н�㡣
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
int  insert (LNode *head, int i,char x);/* i �������λ��*//* x �����������*/

int main ()
{	
	system("color F3");
	int x,y,z;//xΪ�˵�ѡ�� yΪ���� zΪɾ��
	char w;//wΪ�����ַ�
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
	printf("1.��ʼ��\n");
	printf("2.����\n");
	printf("3.ɾ��\n");
	printf("4.��ʾ\n");
	printf("5.�˳�\n");
}



/*��ʼ��*/
int initiate (LNode **head)
{ 
	*head=( LNode * )malloc(sizeof(LNode));
	if (*head==NULL) 
	{   printf("��ʼ��ʧ�ܣ�\n");
		return 0;  }
	(*head)->next=NULL;
	printf("��ɳ�ʼ�� !\n");
	return 1;
}
/*����������*/
int Creat (LNode *head)
{  
	LNode *p,*q;
	int n,i;         /* n ������������Ľ����*/
	char a[10];       /* a �����������������*/
	if(head==NULL)
	{   printf("������δ��ʼ����\n");
		return 0;  }
	printf("�����뵥��������Ľ����n=");
	scanf("%d",&n);
	printf("�������������������ֵ:");
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
			printf("�½��ռ�����ʧ�ܣ�\n");
			return 0;  
		}
		q->data=a[i];
		q->next=NULL;
		p->next=q;
		p=q;   
	}
	return 1;   
}
/*����*/
int  insert (LNode *head, int i,char x)/* i �������λ��*//* x �����������*/
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
			printf("\n����λ�ò�����\n"); 
			return 0;  }
		else
		{   if ((q=( LNode * )malloc(sizeof(LNode)))==NULL)
			{	printf("�½��ռ�����ʧ�ܣ�\n");
				return 0;   
			}
			q->data=x;
			q->next=p->next;
			p->next=q;
		}  
	printf("�������!\n");
	return 1;  
 }
