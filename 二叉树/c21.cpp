#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define NULL 0

typedef struct node
{
	int data;
	struct node *lchild,*rchild;

} bitree;

bitree *root;


bitree* createtree(){
char ch;
bitree *Q[MAXSIZE];
int front,rear;
bitree *root,*s;
root=NULL;
front=1,rear=0;
while((ch=getchar())!='#'){
	s=NULL;
	if(ch!='@'){
		s=(bitree*)malloc(sizeof(bitree));
		s->data=ch;
		s->lchild=NULL;
		s->rchild=NULL;
	}
	rear++;
	Q[rear]=s;
		if(rear==1)
			root=s;
		else{
			if(s&&Q[front]){
				if(rear%2==0)
					Q[front]->lchild=s;
				else
					Q[front]->rchild=s;
			}
			if(rear%2==1)
				front++;
		}
}
return root;
}



void preorder(bitree *p)
{
	if(p!=NULL){
		printf("%c",p->data);
		preorder(p->lchild );
		preorder(p->rchild );
	}
}
void inorder(bitree *p)
{
	if(p!=NULL){	
		inorder(p->lchild );
		printf("%c",p->data);
		inorder(p->rchild );
	}
}

void postorder(bitree *p)
{
	if(p!=NULL){	
		inorder(p->lchild );
		inorder(p->rchild );
		printf("%c",p->data);
	}
}


int printtree(bitree *T,int n)
{
	int i;
	if(T==NULL) return 0;
	printtree(T->rchild,n+1);
	for(i=0;i<n;i++)
		printf("  ");
	printf("%c\n",T->data);
	printtree(T->lchild,n+1);
}
int height(bitree *p)
{
	int hl,hr;
	if(p!=NULL)
	{
		hl=height(p->lchild)+1;
		hr=height(p->rchild)+1;
		
		return hl>hr?hl:hr;

	}
	else return 0;
}
void main(){
	
	int layer=0;
	bitree *T;

    T=createtree();
	printf("前序遍历：\n");
	preorder(T);
	printf("\n");
	printf("中序遍历：\n");
	inorder(T);
	printf("\n");
	printf("后序遍历：\n");
	postorder(T);
	printf("\n");
	layer=height(T);
	printtree(T,layer);
	
}
