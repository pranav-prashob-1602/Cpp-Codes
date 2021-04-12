#include<stdio.h>

char tree[]={'A','B','C','D','F','G','E'};

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

void postOrder(int index) {
    if(tree[index] != '\0' && index>=0) {
        postOrder(getLeftChild(index));
        postOrder(getRightChild(index));
        printf("%c",tree[index]);
    }
}

int main() {
    postOrder(0);
    return 0;
}
