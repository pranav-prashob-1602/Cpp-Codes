#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node *Left,*Right;
    int data;
}node;

node *create() {
    node *p;
    int num;
    printf("\nEnter Data (-1 for no Data) :");
    scanf("%d",&num);
    if(num==-1) {
        return NULL;
    }
    p = (node * )malloc(sizeof(node));
    p->data = num;
    p->Left = NULL;
    p->Right = NULL;
    printf("\nEnter the Left Child of %d",num);
    p->Left = create();
    printf("\nEnter the Right Child of %d",num);
    p->Right = create();
    return p;
}

void preOrder(node *ptr) {
    if(ptr != NULL) {
        printf("%d",ptr->data);
        preOrder(ptr->Left);
        preOrder(ptr->Right);
    }
}

int main() {
    node * root;
    root = create();
    printf("\n\n PreOrder Traversal of the Tree is as Follows:--\n\n");
    preOrder(root);
    return 0;
}
