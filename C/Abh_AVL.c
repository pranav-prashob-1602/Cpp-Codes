#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
    int data;
    struct node *l;
    struct node *r;
    int height;
}avlnode;
avlnode* insert_node(avlnode *p,int);
avlnode* rotL(avlnode *x);
avlnode* rotR(avlnode *x);
avlnode* rotLR(avlnode *x);
avlnode* rotRL(avlnode *x);
avlnode* rotLL(avlnode *x);
avlnode* rotRR(avlnode *x);
void inorder_traversal(avlnode *x);
int cal_height(avlnode *x);
int bf(avlnode *x);
/*
1
12
12
11
13
10
9
15
14
18
7
6
5
4
*/



int main()
{
    int choice,val,n,i;
    avlnode *x;
    avlnode *root=NULL;
    do
    {
        printf("\nAVL TREE OPERATIIONS\n");
        printf("\n1.CREATE NODE\n2.INSERT NODE\n3.DELETE NODE\n4.TRAVESAL\n5.EXIT");
        printf("\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the number of elements:");
            scanf("%d",&n);
            printf("\nenter the data:");
            root=NULL;
            for(i=0;i<n;i++)
            {
                scanf("%d",&val);
                root=insert_node(root,val);
            }
            break;
        case 2:
            printf("\nenter the data:");
            scanf("%d",&val);
            root=insert_node(root,val);
            break;
        case 3:
            //delete_node();
            break;
        case 4:
            inorder_traversal(root);
            break;
        case 5:
            printf("\nBYE BYE....");
            exit(0);
            break;
        default:
            printf("\nplease enter valid choice");
        }
    }
    while(choice!=0);
    return 0;
}
avlnode* insert_node(avlnode * ptr,int x) {
    if(ptr == NULL) {
        ptr = (avlnode *) malloc(sizeof(avlnode));
        ptr->data = x;
        ptr->l = NULL;
        ptr->r = NULL;
    }else {
        if(x > ptr->data) {
            ptr->r = insert_node(ptr->r,x);
            if(bf(ptr) == -2) {
                if(x > ptr->r->data) {
                    ptr = rotRR(ptr);
                } else {
                    ptr = rotRL(ptr);
                }
            }
        }else if(x < ptr->data) {
            ptr->l = insert_node(ptr->l,x);
            if(bf(ptr) == 2) {
                if(x < ptr->l->data) {
                    ptr = rotLL(ptr);
                } else {
                    ptr = rotLR(ptr);
                }
            }
        }
    }
    ptr->height = cal_height(ptr);
    return ptr;
}
avlnode* rotL(avlnode *x)
{
    avlnode *y;
    y=x->r;
    x->r=y->l;
    y->l=x;
    x->height=cal_height(x);
    y->height=cal_height(y);
    return y;
}
avlnode* rotR(avlnode *x)
{
    avlnode *y;
    y=x->l;
    x->l=y->r;
    y->r=x;
    x->height=cal_height(x);
    y->height=cal_height(y);
    return y;
}
avlnode* rotLL(avlnode *p)
{
    p=rotR(p);
    return p;
}
avlnode* rotRR(avlnode *p)
{
    p=rotL(p);
    return p;
}
avlnode* rotLR(avlnode *p)
{
    p->l=rotL(p->l);
    p=rotR(p);
    return p;
}
avlnode* rotRL(avlnode *p)
{
    p->r=rotR(p->r);
    p=rotL(p);
    return p;
}
void inorder_traversal(avlnode *ptr) {
    if(ptr != NULL) {
        inorder_traversal(ptr->l);
        printf("%d (BF = %d)\n",ptr->data,bf(ptr));
        inorder_traversal(ptr->r);
    }
}

int cal_height(avlnode *p)
{
    int lh,rh;
  if(p==NULL)
  {
      return 0;
  }
  if(p->l==NULL)
  {
     lh=0;
  }
  else
  {
     lh=1+p->l->height;
  }
  if(p->r==NULL)
  {
     rh=0;
  }
  else
  {
     rh=1+p->r->height;
  }
  return lh>rh?lh:rh;
}
int bf(avlnode *p)
{
  int lh,rh;
  if(p==NULL)
  {
      return 0;
  }
  if(p->l==NULL)
  {
     lh=0;
  }
  else
  {
     lh=1+p->l->height;
  }
  if(p->r==NULL)
  {
     rh=0;
  }
  else
  {
     rh=1+p->r->height;
  }
  return lh-rh;
}
