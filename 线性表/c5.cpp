#include<stdio.h>
#include<stdlib.h>       
typedef struct node       
{
    int data;            
    struct node *next;    
}linklist;

linklist* create(linklist*L,int n)
{
int i;
linklist*p,*q;
q=(linklist*)malloc(sizeof(linklist));
L=(linklist*)malloc(sizeof(linklist));
L->next=NULL;
q=L;
for(i=0;i<n;i++)
{
p=(linklist*)malloc(sizeof(linklist));
scanf("%d",&p->data);
L->next=p;
p->next=NULL;
L=p;
}
L=q;
return L;
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

void main()
{
linklist *L;
L=create(L,10);
output(L);
}
