#include<iostream>

using namespace std;

static int Max = 0;
static int n = -1;

class NodeStruct {
    public:
        NodeStruct *left,*right;
        int data;
};


class BinaryTree {
    NodeStruct * root;
     public :
        BinaryTree () {
            root = NULL;
        }
        NodeStruct * getRoot();
        void setNode();
        void inOrder(NodeStruct *ptr);
        void preOrder(NodeStruct *ptr);
        void postOrder(NodeStruct *ptr);
        void getHeight(NodeStruct *ptr,int x);
        int getHeight(NodeStruct *ptr);
};

NodeStruct * BinaryTree :: getRoot() {
        return root;
}

void BinaryTree  :: setNode() {
    int num;
    NodeStruct *x,*p,*q;
    x = new NodeStruct();
    x->left = NULL;
    x->right = NULL;
    cout<<"Enter data :";
    cin>>x->data;
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

void BinaryTree  :: getHeight(NodeStruct *ptr,int n) {
    if(ptr == NULL) {
        if(Max<n) {
            Max = n;
        }
        return;
    }else {
        n+=2;
        cout<<"N="<<n;
    }
    getHeight(ptr->left,--n);
    getHeight(ptr->right,--n);
}

int BinaryTree :: getHeight(NodeStruct *ptr) {
    if(ptr==NULL) {
        return -1;
    }else {
        int lHeight = getHeight(ptr->left);
        int rHeight = getHeight(ptr->right);
        if(lHeight>rHeight) {
            return (lHeight+1);
        }
        return (rHeight+1);
    }
}

void BinaryTree  :: inOrder(NodeStruct *ptr) {
    if(ptr == NULL) {
        return;
    }
    inOrder(ptr->left);
    cout<<ptr->data<<" ";
    inOrder(ptr->right);
}

void BinaryTree  :: preOrder(NodeStruct *ptr) {
    if(ptr == NULL) {
        return;
    }
    cout<<ptr->data<<" ";
    inOrder(ptr->left);
    inOrder(ptr->right);
}

void BinaryTree  :: postOrder(NodeStruct *ptr) {
    if(ptr == NULL) {
        return;
    }
    inOrder(ptr->left);
    inOrder(ptr->right);
    cout<<ptr->data<<" ";
}

int main() {
    BinaryTree *b = new BinaryTree();
    b->setNode();
    b->setNode();
    b->setNode();
    b->setNode();
    b->setNode();
    b->setNode();
    b->setNode();
    b->setNode();
    b->setNode();
    b->inOrder(b->getRoot());
    b->getHeight(b->getRoot());
    cout<<"\n"<<b->getHeight(b->getRoot());
    return 0;
}
