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
/*void DeleteNode(linklist *p,linklist *head){
	linklist *q;
	q=head;
	while(q->next!=p)
		q=q->next;
	q->next=p->next;
	free(p);

}*/
void Delete(linklist*L,int i){
	linklist *p,*r;
	int j;
	j=i-1;
	p=Get(L,j);
	if((p!=NULL)&&(p->next!=NULL)){
		r=p->next;
		p->next=r->next;
		free(r);}
	else printf("Not found!\n");
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
	int i;
linklist *L;
printf("单链表元素为：\n");
L=create(L,10);
printf("请输入要删除的位置："); scanf("%d",&i);
Delete(L,i);
output(L);
}
