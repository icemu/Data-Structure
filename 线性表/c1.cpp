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
void output(sqlist *L){
	int i;
	printf("\n˳����е�Ԫ��Ϊ��\n");
    for(i=0;i<=L->length ;i++)
		printf("%d ",L->elem[i]);
	printf("\n");}
void main()
{
	L=creat();
	output(L);
}
