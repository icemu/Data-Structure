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
	printf("������˳����е�Ԫ�أ�\n");
	for(i=0;i<10;i++)
	 {
	 	scanf("%d",&L->elem[i]);
	 	L->length++;
	 }
	return L;
}

int Delete (sqlist *L,int i){
	int j;
	if((i<1)||(i>L->length+1)){
		printf("error\n");
		return 0;
	}
	
	else{
		for(j=i;j<=L->length;j++)
			L->elem[j-1]=L->elem[j];
		    L->length--;		
	}
	return 1;
}

void output(sqlist *L){
	int i;
	printf("\n˳����е�Ԫ��Ϊ��\n");
    for(i=0;i<=L->length ;i++)
		printf("%d ",L->elem[i]);
	printf("\n");}
void main()
{
	int i,l;
	L=creat();
	printf("\n������ɾ����λ�ã�"); scanf("%d",&i);
	l=Delete(L,i);
    if(l)
	output(L);
}
