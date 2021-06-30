#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*left;
    struct node*right;
    int height;
};
struct node*GetNode()
{
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
struct node*MakeNode(int x)
{
    struct node*p;
    p=GetNode();
    p->info=x;
    p->left=NULL;
    p->right=NULL;
    p->height=0;
    return p;
}
struct node*RotateLeft(struct node*x)
{
    struct node*y,*w;
    y=x->right;
    w=y->left;
    y->left=x;
    x->right=w;
    return y;
}
struct node* RotateRight(struct node*x)
{
     struct node*y,*w;
    y=x->left;
    w=y->right;
    y->right=x;
    x->left=w;
    return y;
}
struct node* LL(struct node* x)
{
    struct node*y;
    y=RotateRight(x);
    return y;
}
struct node*RR(struct node* x)
{
    struct node*y;
    y=RotateLeft(x);
    return y;
}
struct node*LR(struct node*x)
{
    struct node*y,*z;
    y=x->left;
    z=RotateLeft(y);
    x->left=z;
    z=RotateRight(x);
    return z;
}
struct node*RL(struct node*x)
{
    struct node*y,*z;
    y=x->right;
    z=RotateRight(y);
    x->right=z;
    z=RotateLeft(x);
    return z;
}
int BFactor(struct node*T)
{
    int lh=0,rh=0;
    if(T->left==NULL)
        lh=0;
    else
        lh=1+(T->left)->height;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+(T->right)->height;
    return lh-rh;
}
int Max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int height(struct node*T)
{
    int lh=0,rh=0;
    if(T->left==NULL)
        lh=0;
    else
        lh=1+(T->left)->height;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+(T->right)->height;
    return Max(lh,rh);
}
struct node* AVLInsert(struct node*T,int x)
{
    if(T==NULL)
        T=MakeNode(x);
    else
    {
        if(x<T->info)
        {
            T->left=AVLInsert(T->left,x);
            if(BFactor(T)==2)
                {
                    if(x<T->left->info)
                        T=LL(T);
                    else
                        T=LR(T);
                }
        }
        else
        {
            T->right=AVLInsert(T->right,x);
            if(BFactor(T)==-2)
                {
                    if(x>T->right->info)
                        T=RR(T);
                    else
                        T=RL(T);
                }
        }
    }
    T->height=height(T);
    return T;
}
struct node*InOrderTraversal(struct node*t)
{
    if(t!=NULL)
    {
        InOrderTraversal(t->left);
        printf("\t%d",t->info);
        InOrderTraversal(t->right);
    }
}
int main()
{

    struct node*root;
    int i,max,min,D;
    struct node*x,*S,*P;
    root=NULL;
    int a[10]={470,50,20,7,45,23,759,64,32,89};
    root=MakeNode(a[0]);
    for(i=1;i<=9;i++)
    {
        root=AVLInsert(root,a[i]);
    }
    InOrderTraversal(root);
    return 0;
}
