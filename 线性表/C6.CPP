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
linklist *Get(linklist *head,int i){
	int j;
	linklist *p;
	p=head;j=0;
	while((p->next!=NULL)&&(j<i)){
		p=p->next;
		j++;
	}
	if(i==j) return p;
	else return NULL;
}


void InsertAfter(linklist *p,int x){
linklist *s;
s=(linklist*)malloc(sizeof(linklist));
s->data=x;
s->next=p->next;
p->next=s;
}

void Insert(linklist *L,int x,int i){
	linklist *p;
	int j;
	j=i;
	p=Get(L,j);
	if(p==NULL) printf("error\n");
	else InsertAfter(p,x);

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
int e,i,I;
linklist *L;
printf("单链表元素为：\n");
L=create(L,10);
printf("请输入插入的元素：");scanf("%d",&e);
printf("请输入插入的位置：");scanf("%d",&i);
Insert(L,e,i);
output(L);
}
