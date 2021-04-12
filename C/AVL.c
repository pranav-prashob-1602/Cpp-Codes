#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
        int data;
        int height;
        struct Node* left, *right;
}node;

node* insert(node *,int );

node*  deleteNode(node *,int );

void inOrder(node *);

node * rotateLeft(node *);
node * rotateRight(node *);
node * RR(node *);
node * LL(node *);
node * RL(node *);
node * LR(node *);
int calcHeight(node *);
int bFactor(node *);

int main() {
    node *root = NULL;
    int ch,n,i,x;
    do{
        printf("\n1 for Create");
        printf("\n2 for Insertion ");
        printf("\n3 for Deletion");
        printf("\n4 for Traversal");
        printf("\n5 to Exit");
        printf("\n\nEnter your choice :\t");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            printf("\n\nEnter the number of elements :\t");
            scanf("%d",&n);
            printf("\nEnter tree data :");
            root = NULL;
            for(i=0;i<n;i++) {
                    scanf("%d",&x);
                    root = insert(root,x);
            }
            break;
        case 2:
             printf("\nEnter tree data :");
             scanf("%d",&x);
             root = insert(root,x);
             break;
        case 4:
            inOrder(root);
            break;
        }
    }while(ch!=5);
    return 0;
}

int calcHeight(node *ptr) {
    int lH,rH;
    if(ptr == NULL) {
        return 0;
    }
    if(ptr->left == NULL) {
        lH = 0;
    }else {
        lH = 1 + ptr->left->height;
    }
    if(ptr->right == NULL) {
        rH = 0;
    }else {
        rH = 1 + ptr->right->height;
    }
    /*if(lH>rH) {
        return lH;
    }
    return rH;*/
    return lH > rH ? lH : rH;
}

node * rotateLeft(node * x) {
    node * y;
    y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = calcHeight(x);
    y->height = calcHeight(y);
    return y;
}

node * RR(node *ptr) {
    ptr = rotateLeft(ptr);
    return ptr;
}

node * rotateRight(node * x) {
    node * y;
    y = x->left;
    x->left = y->right;
    y->right = x;
    x->height = calcHeight(x);
    y->height = calcHeight(y);
    return y;
}

node * LL(node *ptr) {
    ptr = rotateRight(ptr);
    return ptr;
}

node * LR(node *ptr) {
    ptr->left = rotateLeft(ptr->left);
    ptr = rotateRight(ptr);
    return ptr;
}

node * RL(node *ptr) {
    ptr->right = rotateRight(ptr->right);
    ptr = rotateLeft(ptr);
    return ptr;
}

int bFactor(node *ptr) {
    /*int left = calcHeight(ptr->left);
    int right = calcHeight(ptr->right);
    return left-right;*/
    int lH,rH;
    if(ptr == NULL)
        return 0;
    if(ptr->left == NULL) {
        lH = 0;
    }else {
        lH = 1 + ptr->left->height;
    }
    if(ptr->right == NULL) {
        rH = 0;
    }else {
       rH = 1 + ptr->right->height;
    }
    return lH-rH;
}

node* insert(node * ptr,int x) {
    if(ptr == NULL) {
        ptr = (node *) malloc(sizeof(node));
        ptr->data = x;
        ptr->left = NULL;
        ptr->right = NULL;
    }else {
        if(x > ptr->data) {
            ptr->right = insert(ptr->right,x);
            if(bFactor(ptr) == -2) {
                if(x > ptr->right->data) {
                    ptr = RR(ptr);
                } else {
                    ptr = RL(ptr);
                }
            }
        }else if(x < ptr->data) {
            ptr->left = insert(ptr->left,x);
            if(bFactor(ptr) == 2) {
                if(x < ptr->left->data) {
                    ptr = LL(ptr);
                } else {
                    ptr = LR(ptr);
                }
            }
        }
    }
    ptr->height = calcHeight(ptr);
    return ptr;
}

void inOrder(node *ptr) {
    if(ptr != NULL) {
        inOrder(ptr->left);
        printf("%d (BF = %d)\n",ptr->data,bFactor(ptr));
        inOrder(ptr->right);
    }
}


