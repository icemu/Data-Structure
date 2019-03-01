#include<stdio.h>
#include<stdlib.h>       
typedef struct node       
{
    int data;            
    struct node *next;    
}linklist;

linklist* create(int n)
{
int i;
linklist*p,*q,*L;
q=(linklist*)malloc(sizeof(linklist));
L=(linklist*)malloc(sizeof(linklist));
L->next=NULL;
q=L;
for(i=1;i<=n;i++)
{
p=(linklist*)malloc(sizeof(linklist));
scanf("%d",&p->data);
q->next=p;
p->next=NULL;
q=p;
}
 
return L;
}

void Merge(linklist *LA,linklist *LB,linklist *LC){
	linklist *pa,*pb,*pc;
	pa=LA->next;pb=LB->next;
   	pc=LC;
	while(pa&&pb){
		if(pa->data<=pb->data){
			pc->next=pa;pc=pa;pa=pa->next;
		}
		else{pc->next =pb;pc=pb;pb=pb->next;}
	}
	pc->next=pa?pa:pb;
	
	free(LB);

}
void output(linklist *h){
linklist *p;
p=h->next;
while(p)
{printf("%d ",p->data);
p=p->next;
}
printf("\n");
}

int main()
{
linklist *LA,*LB,*LC;
printf("请输入链表A中的元素：");
LA=create(5);
printf("LA=");
output(LA);
printf("请输入链表B中的元素：");
LB=create(7);
printf("LB=");
output(LB);



LC=create(0);  
Merge(LA,LB,LC);
printf("LC=");
output(LC);
return 0;
}

