/*ʵ����  ˳����ҺͶ��ֲ��ң�2ѧʱ��
һ��ʵ��Ŀ��
��������˳����ҺͶ��ֲ��ҵĻ���˼�룬���ҹ��̼���ʵ�ֵ��㷨��
����ʵ������
����֪�ؼ������зֱ����˳����ҺͶ��ֲ��ҡ�
��������Ҫ��
����        ��1�������ؼ�������ͨ�������������룻
����        ��2�����ҷ�ʽ�����û�ѡ��
����        ��3��������Ҽ�¼��λ�ã�
            ��4�������û�ѡ���˳�����
����ʵ��Ҫ�㼰˵��
����˳�������һ�ּ򵥵Ĳ��ҷ��������ݼ�¼˳������ĳ˳����С�˳�����ҵķ����ǣ���˳����һ�˿�ʼ���ø���ֵ���˳�������и���¼�Ĺؼ�����Ƚϣ����ڱ����ҵ�ĳ����¼�Ĺؼ��������ֵ��ȣ��������ҳɹ���
�������ֲ����ֳƶ��ֲ��ң���Ҫ������ҵ�˳������������������и���¼����ؼ���ֵ�Ĵ�С˳��洢��
�ɰ����¸�ʽ�����¼�Ľṹ��
                  typedef  struct  
                 {int  key;
                  Char data;
             }datatype;
����ģ�黮�֣���1��getsort( )�����������¼�Ĺؼ���
         ��2��seqsearch ( )������˳�����
         ��3��binsearch( )���������ֲ���
         ��4��insertsort( )������ֱ�Ӳ�������
         ��5��print( )��������ʾ���*/
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
{   int sel,n,s,key,i;   /*sel ����ѡ��n ��¼���ȣ�s ���ҷ�����ѡ��key ���ҹؼ��ָ���ֵ��i Ŀ���¼���±�*/
	datatype x[MAXLEN];
	printf("���������ѡ��1---��ʼ ����ѡ��Ϊ�˳� \nyour choice =");
	scanf("%d",&sel);
	while(sel==1)
	{   printf("\n����ؼ������У��ԣ�1�������룺");
		n=getsort(x );
		printf("������ѡ��Ĳ��ҷ�����1---˳����� 2---���ֲ��� 3-�˳�����\nyour choice =");
		scanf("%d",&s);
		while(s!=3)
		{   printf("��������ҹؼ��ָ���ֵkey��");
			scanf("%d",&key);
			if(s==1)
			{   printf("\nԭ�ؼ�������Ϊ��");
				print(x,n);
				i=seqsearch(x,key,n);
				if(i==-1)
					printf("\nû�и���ֵ��¼��\n");
				else
					printf("\n���ҵĽ��Ϊ���еĵ� %d ����¼!\n",i+1);  }
			else if(s==2)
			{   i= binsearch(x,key,n );
				if(i==-1)
					printf("\nû�и���ֵ��¼��\n");
				else
					printf("\n���ҵĽ��Ϊ���еĵ� %d ����¼!\n",i+1);   }
			else
				printf("ѡ�����\n");
			printf("������ѡ��Ĳ��ҷ�����1---˳����� 2---���ֲ��� 3-�˳�����\nyour choice =");
			scanf("%d",&s);   }
		printf("���������ѡ��1---��ʼ ����ѡ��Ϊ�˳� \nyour choice =");
		scanf("%d",&sel);  }  }
/*�����¼�Ĺؼ���*/
int getsort(datatype x[] )
{   int i=0;
	scanf("%d",&x[i].key);
	while(x[i].key!=-1)
	{   i++;
		scanf("%d",&x[i].key);  }
	return i;  }
/*˳�����*/
int seqsearch(datatype x[],int key,int n)
{   int i;
	for(i=0;i<n;i++)
	{   if(key==x[i].key)
			return i;  }
	return -1;  }
/*���ֲ���*/
int binsearch(datatype x[],int key, int n)
{   int low,mid,hig;                /*����λ��ָʾ��*/
	datatype y[MAXLEN];
	low=0;
	hig=n-1;
	for(int i=0;i<n;i++)
		y[i]=x[i];
	insertsort(y,n);                   /*����*/
	printf("\n�����ؼ�������Ϊ��");
	print(y,n);
	while(low<=hig)                 /*����*/
	{   mid=(low+hig)/2;
		if(key ==y[mid].key)
			return mid;
		else if(key >y[mid].key)
			low=mid+1;
		else
			hig=mid-1;  }
	return -1;  }
/*ֱ�Ӳ�������*/
void insertsort(datatype x[],int n)
{   int i,j;
	datatype temp;          /*�м����*/
	for(i=1;i<n;i++)
	{   temp=x[i];
		j=i-1;
		while(j>-1 && temp.key<x[j].key)
		{   x[j+1]=x[j];
			j--;  }
		x[j+1]=temp;  }  }
/*��ʾ���*/
void print(datatype x[],int n)
{   int i;
	for(i=0;i<n;i++)
		printf("%d\t",x[i]);
	printf("\n");   }