#include<stdio.h>
#include<stdlib.h>

static int flag = 0;

typedef struct Node {
    struct Node *left,*right;
    int data;
}myNode;

myNode * root = NULL;

void setNode() {
    int num;
    myNode *x,*p,*q;
    x = (myNode*)malloc(sizeof(myNode));
    x->left = NULL;
    x->right = NULL;
    printf("Enter data :");
    scanf("%d",&x->data);
    if(root == NULL ) {
        root = x;
        return;
    }
    p = root;
    while(p!=NULL) {
        q=p;
        if(x->data < p->data) {
            p = p->left;
        }else {
            p = p->right;
        }
    }
    if(x->data < q->data) {
        q->left = x;
    }else {
        q->right = x;
    }
}

myNode* findInOrderSuccessor(myNode * ptr) {
    myNode *q = ptr;
    while(q->left != NULL) {
        q = q->left;
    }
    return q;
}


myNode* deleteNode(myNode *ptr, int key) {
    if(ptr == NULL) {
            return ptr;
    }else if(key < ptr->data) {
        ptr->left = deleteNode(ptr->left,key);
    }else if(key > ptr->data) {
        ptr->right = deleteNode(ptr->right,key);
    }else {
        if(ptr->left == NULL) {
            myNode *temp;
            temp = ptr->right;
            free(ptr);
            return temp;
        }else if(ptr->right == NULL) {
            myNode *temp;
            temp = ptr->left;
            free(ptr);
            return temp;
        }
        myNode *temp;
        temp = findInOrderSuccessor(ptr->right);
        ptr->data = temp->data;
        ptr->right = deleteNode(ptr->right,temp->data);
        flag =1;
    }
    return ptr;
}

void deleteTreeNode(myNode *ptr, int key) {
    if(ptr == NULL) {
        printf("\n\nTree is Empty");
    }
    myNode * temp = deleteNode(ptr, key);
    if(!flag) {
        printf("\n\nNot Found");
    }
}


void inOrder(myNode *ptr) {
    if(ptr == NULL) {
        return;
    }
    inOrder(ptr->left);
    printf("%d ",ptr->data);
    inOrder(ptr->right);
}

int main() {
    setNode();
    setNode();
    setNode();
    setNode();
    setNode();
    setNode();
    setNode();
    setNode();
    setNode();
    inOrder(root);
    deleteTreeNode(root, 4);
    printf("\n");
    inOrder(root);
    return 0;
}
