#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100  //设记录不超过二十个

typedef struct    //定义每个记录
{
	char name[MAXSIZE]; //姓名
	char sex[3]; //性别
	float num; //学号
	float sum; //总分 
	float ave; //平均分
	float mark1;//成绩一
	float mark2;//成绩二
	float mark3;//成绩三
}Student;

typedef struct  //定义顺序表的结构
{
	Student r[MAXSIZE+1];//存储顺序表的向量
	int length; //顺序表的长度
}SqList;

void create(SqList &ST)     //创建学生的相关信息
{
	int i;
	printf("请输入学生的个数:\n");
	scanf("%d",&ST.length);
	for(i=0;i<ST.length;i++)
	{
		printf("请输入第%d+1个学生的信息:\n",i);
		printf("学号:\n");
		scanf("%f",&ST.r[i].num);
		printf("姓名:\n");
		scanf("%s",&ST.r[i].name);
		printf("性别:\n");
		scanf("%s",&ST.r[i].sex);
		printf("成绩一:\n");
		scanf("%f",&ST.r[i].mark1);
		printf("成绩二:\n");
		scanf("%f",&ST.r[i].mark2);
		printf("成绩三:\n");
		scanf("%f",&ST.r[i].mark3);

	}
	printf("输入完毕！\n");
}


void sum(SqList &ST)  //计算总分
{
	int i;
	for(i=0;i<ST.length;i++)
	{
		ST.r[i].sum=ST.r[i].mark1+ST.r[i].mark2+ST.r[i].mark3;
	}
}

void shuchu(SqList &ST)  //输出函数
{
	int i;
	printf("学生的信息如下:\n");
	printf("学号  姓名  性别  成绩一  成绩二  成绩三  总分\n");
	for(i=0;i<ST.length;i++)
	{
		printf("%f  %s  %s  %f  %f  %f  %f\n",ST.r[i].num,ST.r[i].name,ST.r[i].sex,ST.r[i].mark1,ST.r[i].mark2,ST.r[i].mark3,ST.r[i].sum);
	}
}

void caidan(SqList &ST);
/*************************************chacunbufen*****************************/
void chaxun(SqList &ST)  //查询信息
{
   l1:printf("查询可以选择以下方法:\n");
	printf("1:根据学号查询\n");
	printf("2:根据姓名查询\n");
	printf("3:根据性别查询\n");
	printf("4:退出\n");
	int n,m;
	char name[MAXSIZE];
	char xb[3];
	printf("请选择!\n");
	scanf("%d",&m);

	if(m==1) //折半查找
	{
		int i,j;
		Student L1;//使学号变为有序的
		for(i=1;i<ST.length;i++)
			for(j=i;j>=1;j--)
				if(ST.r[j].num<ST.r[j-1].num)
				{
					L1=ST.r[j];
					ST.r[j]=ST.r[j-1];
					ST.r[j-1]=L1;
				}
       l2:int a=0;
		printf("请输入需要查找的学号:\n");
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
           printf("所查信息不存在！\n请重新输入！");
		   goto l2;
		}
		goto l1;
	}

	if(m==2)//顺序查找
	{
l3:int a=0,i;
		printf("输入要查找的姓名:\n");
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
			printf("所查信息不存在！\n请重新输入！\n");
			goto l3;
		}
		goto l1;

	}

	if(m==3)//顺序查找
	{
l4:int a=0,i;
   printf("请输入需要查的性别：\n");
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
	   printf("所查信息不存在！请重新输入！\n");
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
void paixu(SqList &ST) //排序
{
l1:int n;
   printf("排序有以下方法可供选择:\n");
   printf("1:根据学号排序\n");
   printf("2:根据成绩一排序\n");
   printf("3:根据成绩二排序\n");
   printf("4:根据成绩三排序\n");
   printf("5:根据总成绩排序\n");
   printf("6:退出\n");
   printf("请选择！\n");
   scanf("%d",&n);
   if(n==1)//按照学号排序,使用插入排序
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
			   printf("排序完成！\n");
			   goto l1;
   }
   if(n==2)//根据成绩一排序，用选择排序
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
		   printf("排序完成！\n");
		   goto l1;
   }
   if(n==3)//根据成绩二排序，用选择排序
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
		   printf("排序完成！\n");
		   goto l1;
   }
if(n==4)//根据成绩三排序，用选择排序
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
		   printf("排序完成！\n");
		   goto l1;
   }
if(n==5)//根据总成绩排序，用选择排序
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
		   printf("排序完成！\n");
		   goto l1;
   }
if(n==6)//退出
{
	caidan(ST);
}
}

void caidan(SqList &ST)//选择菜单
{
	printf("请选择要进入的模块:\n");
	printf("1:查询\n");
	printf("2:排序\n");
	printf("3:退出\n");
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

/***********************主函数************************/
void main()
{
	SqList ST;
	create(ST);
	sum(ST);
	shuchu(ST);
	caidan(ST);
}
