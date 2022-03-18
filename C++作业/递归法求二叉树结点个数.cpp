#include <iostream>
using namespace std;
typedef struct BTnode
{
	struct BTnode* lchild;
	struct BTnode* rchild;
	int data;
}BTnode;
void cratenode(BTnode*&a,int n)
{
	a=(BTnode*)malloc(sizeof(BTnode));
	a->data=n;
}
//递归法求二叉树结点个数 
int Findbtnum(BTnode* root)
{
	if(root==NULL)
	{
		return 0;
	}
	else if(root->lchild==NULL&&root->rchild==NULL)
	{
		return 1;	
	}
	else return Findbtnum(root->lchild)+Findbtnum(root->rchild)+1;
} 
int main()
{
	BTnode*a=NULL;
	cratenode(a,0);
	BTnode*b=NULL;
	cratenode(b,1);
	BTnode*c=NULL;
	cratenode(c,2);
	BTnode*d=NULL;
	cratenode(d,3);
	BTnode*e=NULL;
	cratenode(e,4);
	BTnode*f=NULL;
	cratenode(f,5);
	BTnode*g=NULL;
	cratenode(g,6);
	a->lchild=b;a->rchild=c;
	b->lchild=d;b->rchild=e;
	c->lchild=f;c->rchild=NULL;
	d->lchild=NULL;d->rchild=NULL;
	e->lchild=NULL;e->rchild=NULL;
	f->lchild=NULL;f->rchild=g;
	g->lchild=NULL;g->rchild=NULL;

//	a->lchild=NULL;a->rchild=NULL;
	printf("%d",Findbtnum(a));
	return 0;
}

