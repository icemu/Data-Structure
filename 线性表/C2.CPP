#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int elemtype;
typedef struct {
	elemtype elem[MAXSIZE];
	int length;
}sqlist;
sqlist *L;

sqlist *creat(){
	int i=0;
	L=(sqlist*)malloc(sizeof(sqlist));
	L->length=-1;
	printf("请输入顺序表中的元素：\n");
	for(i=0;i<10;i++)
	 {
	 	scanf("%d",&L->elem[i]);
	 	L->length++;
	 }
	return L;
}

int insert(sqlist *L,int x,int i){
	int j;
	if((L->length)>=MAXSIZE-1){
		printf("overflow\n");
		return 0;
	}
	else if ((i<1)||(i>(L->length)+2)){
		printf("error\n");
		return 0;
	}
	else{
		for(j=L->length;j>=i-1;j--)
			L->elem[j+1]=L->elem[j];
		    L->elem[i-1]=x;
		    L->length=L->length+1;
	}
	return 1;
}

void output(sqlist *L){
	int i;
	printf("\n顺序表中的元素为：\n");
    for(i=0;i<=L->length ;i++)
		printf("%d ",L->elem[i]);
	printf("\n");}
void main()
{
	int e,i,l;
	L=creat();
    printf("\n请输入插入的元素："); scanf("%d",&e);
	printf("\n请输入插入的位置："); scanf("%d",&i);
	l=insert(L,e,i);
    if(l)
	output(L);
}
