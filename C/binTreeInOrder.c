#include<stdio.h>

#define size 40

char tree[size];

int getRightChild(int index) {
    //printf("r%d\n",index);
    if(tree[index] != '\0' && 2*index + 2 < (sizeof(tree)/sizeof(char))) {
        int rIndex = 2*index +2;
        if(tree[rIndex] != '\0') {
            return rIndex;
        }
    }
    return -1;
}

int getLeftChild(int index) {
    //printf("l%d\n",index);
    if(tree[index] != '\0' && 2*index + 1 < (sizeof(tree)/sizeof(char))) {
        int lIndex = 2*index +1;
        if(tree[lIndex] != '\0') {
            return lIndex;
        }
    }
    return -1;
}

void InOrder(int index) {
    if(tree[index] != '\0' && index >= 0) {
        InOrder(getLeftChild(index));
        printf("%c",tree[index]);
        InOrder(getRightChild(index));
    }
}

void setLeft(char child,int index) {
    if(tree[index] == '\0' || index<0)
    {
       printf("\nCan't set Child\n");
    } else {
        int lIndex=2*index+1;
        tree[lIndex]=child;
    }
}

void setRight(char child,int index) {
    if(tree[index] == '\0' || index<0)
    {
        printf("\nCan't set Child\n");
    } else {
        int rIndex=2*index+2;
        tree[rIndex]=child;
    }
}

void setRoot(char child) {
    if(tree[0] != '\0') {
        printf("FATAL ERROR OCCURRED");
        return;
    }
    tree[0] =child;
}

int main() {
    setRoot('A');
    setLeft('B',0);
    setLeft('C',2);
    setLeft('D',1);
    setRight('C',0);
    setRight('E',1);
    printf("\n\n\n");
    InOrder(0);
    return 0;
}
