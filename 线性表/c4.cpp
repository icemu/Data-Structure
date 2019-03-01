#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int elemtype;
typedef struct {
	elemtype elem[MAXSIZE];
	int length;
	int listsize;

}sqlist;
int Insert(sqlist *L,int i,int x){
	int j;
	if((L->length)>=MAXSIZE-1){
		return 0;
	}
	else if ((i<1)||(i>(L->length)+2)){
		return 0;
	}
	else{
		if(L->length==0)  L->elem[0]=x; 
		else
	{
			for(j=L->length;j>=i-1;j--)
			L->elem[j+1]=L->elem[j];
		    L->elem[i-1]=x;
			}
		    L->length=L->length+1;
}
	return 1;
}

void Merge(sqlist LA,sqlist LB,sqlist *LC){
	elemtype *pa,*pb,*pc,*pa_last,*pb_last;
	pa=LA.elem;pb=LB.elem;
	LC->length=LA.length+LB.length;
    pc=LC->elem;
		pa_last=LA.elem+LA.length-1;
	    pb_last=LB.elem+LB.length-1;
		while(pa<=pa_last&&pb<=pb_last){
			if(*pa<*pb) *pc++=*pa++;
			else *pc++=*pb++;}
		while(pa<=pa_last) *pc++=*pa++;
		while(pb<=pb_last) *pc++=*pb++;
}

void output(sqlist L){
	    int i;
	    for(i=0;i<L.length ;i++)
		printf("%d ",L.elem[i]);
     	printf("\n");}

int main()
{
sqlist LA,LB,LC;
int j;

	LA.length=0;
	LA.listsize=MAXSIZE;
	
	LB.length=0;
	LB.listsize=MAXSIZE;
	
	LC.length=0;
	LC.listsize=MAXSIZE;

for(j=0;j<=5;j++)
Insert(&LA,j,j);
printf("\n顺序表LA中元素为：");
output(LA);

for(j=0;j<=5;j++)
Insert(&LB,j,2*j);
printf("\n顺序表LB中元素为：");
output(LB);

Merge(LA,LB,&LC);
printf("\n顺序表LC中元素为：");
output(LC);
return 0;
}
	