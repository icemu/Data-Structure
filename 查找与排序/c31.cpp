#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100  //���¼��������ʮ��

typedef struct    //����ÿ����¼
{
	char name[MAXSIZE]; //����
	char sex[3]; //�Ա�
	float num; //ѧ��
	float sum; //�ܷ� 
	float ave; //ƽ����
	float mark1;//�ɼ�һ
	float mark2;//�ɼ���
	float mark3;//�ɼ���
}Student;

typedef struct  //����˳���Ľṹ
{
	Student r[MAXSIZE+1];//�洢˳��������
	int length; //˳���ĳ���
}SqList;

void create(SqList &ST)     //����ѧ���������Ϣ
{
	int i;
	printf("������ѧ���ĸ���:\n");
	scanf("%d",&ST.length);
	for(i=0;i<ST.length;i++)
	{
		printf("�������%d+1��ѧ������Ϣ:\n",i);
		printf("ѧ��:\n");
		scanf("%f",&ST.r[i].num);
		printf("����:\n");
		scanf("%s",&ST.r[i].name);
		printf("�Ա�:\n");
		scanf("%s",&ST.r[i].sex);
		printf("�ɼ�һ:\n");
		scanf("%f",&ST.r[i].mark1);
		printf("�ɼ���:\n");
		scanf("%f",&ST.r[i].mark2);
		printf("�ɼ���:\n");
		scanf("%f",&ST.r[i].mark3);

	}
	printf("������ϣ�\n");
}


void sum(SqList &ST)  //�����ܷ�
{
	int i;
	for(i=0;i<ST.length;i++)
	{
		ST.r[i].sum=ST.r[i].mark1+ST.r[i].mark2+ST.r[i].mark3;
	}
}

void shuchu(SqList &ST)  //�������
{
	int i;
	printf("ѧ������Ϣ����:\n");
	printf("ѧ��  ����  �Ա�  �ɼ�һ  �ɼ���  �ɼ���  �ܷ�\n");
	for(i=0;i<ST.length;i++)
	{
		printf("%f  %s  %s  %f  %f  %f  %f\n",ST.r[i].num,ST.r[i].name,ST.r[i].sex,ST.r[i].mark1,ST.r[i].mark2,ST.r[i].mark3,ST.r[i].sum);
	}
}

void caidan(SqList &ST);
/*************************************chacunbufen*****************************/
void chaxun(SqList &ST)  //��ѯ��Ϣ
{
   l1:printf("��ѯ����ѡ�����·���:\n");
	printf("1:����ѧ�Ų�ѯ\n");
	printf("2:����������ѯ\n");
	printf("3:�����Ա��ѯ\n");
	printf("4:�˳�\n");
	int n,m;
	char name[MAXSIZE];
	char xb[3];
	printf("��ѡ��!\n");
	scanf("%d",&m);

	if(m==1) //�۰����
	{
		int i,j;
		Student L1;//ʹѧ�ű�Ϊ�����
		for(i=1;i<ST.length;i++)
			for(j=i;j>=1;j--)
				if(ST.r[j].num<ST.r[j-1].num)
				{
					L1=ST.r[j];
					ST.r[j]=ST.r[j-1];
					ST.r[j-1]=L1;
				}
       l2:int a=0;
		printf("��������Ҫ���ҵ�ѧ��:\n");
		scanf("%d",&n);
		int low,high,mid;
		low=0;
		high=ST.length-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(n==ST.r[mid].num)
			{
               printf("%f  %s  %s  %f  %f  %f  %f\n",ST.r[mid].num,ST.r[mid].name,ST.r[mid].sex,ST.r[mid].mark1,ST.r[mid].mark2,ST.r[mid].mark3,ST.r[mid].sum);
			   a=1;
			   break;
			}
			else if(n<ST.r[mid].num)
				high=mid-1;
			else
				low=mid+1;
			
		}
		if(!a)
		{
           printf("������Ϣ�����ڣ�\n���������룡");
		   goto l2;
		}
		goto l1;
	}

	if(m==2)//˳�����
	{
l3:int a=0,i;
		printf("����Ҫ���ҵ�����:\n");
		scanf("%s",&name);
		for(i=0;i<ST.length;i++)
		{
			if(strcmp(name,ST.r[i].name)==0)
			{
                printf("%f  %s  %s  %f  %f  %f  %f\n",ST.r[i].num,ST.r[i].name,ST.r[i].sex,ST.r[i].mark1,ST.r[i].mark2,ST.r[i].mark3,ST.r[i].sum);
			   a=1;
			}
		}
		if(!a)
		{
			printf("������Ϣ�����ڣ�\n���������룡\n");
			goto l3;
		}
		goto l1;

	}

	if(m==3)//˳�����
	{
l4:int a=0,i;
   printf("��������Ҫ����Ա�\n");
   scanf("%s",&xb);
   for(i=0;i<ST.length;i++)
   {
	   if(strcmp(xb,ST.r[i].sex)==0)
	   {
          printf("%f  %s  %s  %f  %f  %f  %f\n",ST.r[i].num,ST.r[i].name,ST.r[i].sex,ST.r[i].mark1,ST.r[i].mark2,ST.r[i].mark3,ST.r[i].sum);
		  a=1;
	   }
   }
   if(!a)
   {
	   printf("������Ϣ�����ڣ����������룡\n");
	   goto l4;
   }
   goto l1;
	}

	if(m==4)
	{
		caidan(ST);
	}

}

/***********************************paixubufen**********************************/
void paixu(SqList &ST) //����
{
l1:int n;
   printf("���������·����ɹ�ѡ��:\n");
   printf("1:����ѧ������\n");
   printf("2:���ݳɼ�һ����\n");
   printf("3:���ݳɼ�������\n");
   printf("4:���ݳɼ�������\n");
   printf("5:�����ܳɼ�����\n");
   printf("6:�˳�\n");
   printf("��ѡ��\n");
   scanf("%d",&n);
   if(n==1)//����ѧ������,ʹ�ò�������
   {
	   int i,j;
	   Student L1;
	   for(i=1;i<ST.length;i++)
		   for(j=i;j>=1;j--)
		   {
			   if(ST.r[j].num<ST.r[j-1].num)
			   {
				   L1=ST.r[j];
				   ST.r[j]=ST.r[j-1];
				   ST.r[j-1]=L1;
			   }
		   }
			   shuchu(ST);
			   printf("������ɣ�\n");
			   goto l1;
   }
   if(n==2)//���ݳɼ�һ������ѡ������
   {
	   Student L1;
	   int i,j;
	   for(i=0;i<ST.length;i++)
		   for(j=i+1;j<ST.length;j++)
		   {
			   if(ST.r[i].mark1>ST.r[j].mark1)
			   {
				   L1=ST.r[j];
				   ST.r[j]=ST.r[i];
				   ST.r[i]=L1;
			   }
		   }
		   shuchu(ST);
		   printf("������ɣ�\n");
		   goto l1;
   }
   if(n==3)//���ݳɼ���������ѡ������
   {
	   Student L1;
	   int i,j;
	   for(i=0;i<ST.length;i++)
		   for(j=i+1;j<ST.length;j++)
		   {
			   if(ST.r[i].mark2>ST.r[j].mark2)
			   {
				   L1=ST.r[j];
				   ST.r[j]=ST.r[i];
				   ST.r[i]=L1;
			   }
		   }
		   shuchu(ST);
		   printf("������ɣ�\n");
		   goto l1;
   }
if(n==4)//���ݳɼ���������ѡ������
   {
	   Student L1;
	   int i,j;
	   for(i=0;i<ST.length;i++)
		   for(j=i+1;j<ST.length;j++)
		   {
			   if(ST.r[i].mark3>ST.r[j].mark3)
			   {
				   L1=ST.r[j];
				   ST.r[j]=ST.r[i];
				   ST.r[i]=L1;
			   }
		   }
		   shuchu(ST);
		   printf("������ɣ�\n");
		   goto l1;
   }
if(n==5)//�����ܳɼ�������ѡ������
   {
	   Student L1;
	   int i,j;
	   for(i=0;i<ST.length;i++)
		   for(j=i+1;j<ST.length;j++)
		   {
			   if(ST.r[i].sum>ST.r[j].sum)
			   {
				   L1=ST.r[j];
				   ST.r[j]=ST.r[i];
				   ST.r[i]=L1;
			   }
		   }
		   shuchu(ST);
		   printf("������ɣ�\n");
		   goto l1;
   }
if(n==6)//�˳�
{
	caidan(ST);
}
}

void caidan(SqList &ST)//ѡ��˵�
{
	printf("��ѡ��Ҫ�����ģ��:\n");
	printf("1:��ѯ\n");
	printf("2:����\n");
	printf("3:�˳�\n");
	int c;
	scanf("%d",&c);
	if(c==1)
	{
		chaxun(ST);
	}
	if(c==2)
	{
		paixu(ST);
	}
	if(c==3)
	{
		exit(0);
	}
}

/***********************������************************/
void main()
{
	SqList ST;
	create(ST);
	sum(ST);
	shuchu(ST);
	caidan(ST);
}
