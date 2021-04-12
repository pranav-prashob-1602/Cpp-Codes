#include<iostream>

using namespace std;

class BTreeNode {
    int *keys;
    BTreeNode **child_ptr;
    int t;   //Minimum Degree
    int n;  //Current No. of keys in a node
    bool isLeaf;
public:
    BTreeNode(int t,bool isLeaf) {
        this->t = t;
        this->isLeaf = isLeaf;
        keys = new int[2*t-1];
        child_ptr = new BTreeNode *[2*t];
        n=0;
    }
    void insertNonFull(int k);
    void splitChild(int i,BTreeNode *y);
    void traverse();
    BTreeNode* searchTree(int k);
    friend class BTree;
};

class BTree {
        BTreeNode *root;
        int t;  //Minimum Degree
    public:
        BTree(int t) {
            root = NULL;
            this->t = t;
        }
        void insertNode(int k);
        void traverseTree();
        BTreeNode * searchNode(int key);
};

void BTreeNode :: insertNonFull(int k) {
    int i = n-1;
    if (isLeaf) {
        while(i>=0 && keys[i] > k) {
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = k;
        n++;
    }else {
        while(i>=0 && keys[i] > k) {
            i--;
        }
        if(child_ptr[i+1]->n == 2*t -1) {
            splitChild(i+1,child_ptr[i+1]);
            if(keys[i+1] < k) {
                i++;
            }
        }
        child_ptr[i+1]->insertNonFull(k);
    }
}

void BTreeNode :: splitChild(int i,BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t,y->isLeaf);
    z->n = t-1;
    for(int j=0;j<t-1;j++) {
        z->keys[j] = y->keys[j+t];
    }
    y->n=t-1;
    if(!y->isLeaf) {
        for(int j=0;j<t;j++) {
            z->child_ptr[j] = y->child_ptr[j+t];
        }
    }
    for(int j=n;j>=i+1;j--) {
        child_ptr[j+1] = child_ptr[j];
    }
    child_ptr[i+1] = z;
    for(int j=n-1;j>=i;j--) { // WE HAVE TO DISCOVER THIS..DEW PII
        keys[j+1] = keys[j];
    }
    keys[i] = y->keys[t-1];
    n+=1;
}

void BTree :: insertNode(int k) {
    if(root == NULL) {
        root = new BTreeNode(t,true);
        root->keys[0] = k;
        root->n = 1;
    }else {
        if(root->n == 2*t-1) {
            BTreeNode *s = new BTreeNode(t,false);
            s->child_ptr[0] = root;
            s->splitChild(0,root);
            int i=0;
            if(s->keys[0] < k) {
                i++;
            }
            s->child_ptr[i]->insertNonFull(k);
            root = s;
        }else {
            root->insertNonFull(k);
        }
    }
}

void BTreeNode :: traverse() {
    int i;
    for(i=0;i<n;i++) {
        if(!isLeaf) {
            child_ptr[i]->traverse();
        }
        cout<<keys[i]<<" ";
    }
    if(!isLeaf) {
            child_ptr[i]->traverse();
    }
}

void BTree :: traverseTree() {
    if(root!=NULL) {
        root->traverse();
    }
}

BTreeNode* BTreeNode :: searchTree(int k) {
    int i=0;
    while(i<n && keys[i] < k) {
        i++;
    }
    if(keys[i] == k) {
        return this;
    }
    if(isLeaf) {
        return NULL;
    }
    return child_ptr[i]->searchTree(k);
}

BTreeNode* BTree :: searchNode(int key) {
    return (root == NULL ? NULL : root->searchTree(key));
}

int main() {
    BTree t(3);     //Order = 6, Minimum deg=3, Maximum = 5
    t.insertNode(10);
    t.insertNode(20);
    t.insertNode(5);
    t.insertNode(6);
    t.insertNode(12);
    t.insertNode(15);
    t.traverseTree();
    BTreeNode * s = t.searchNode(10);
    if(s==NULL) {
        cout<<"\nNOT FOUND\n";
    }else {
        cout<<"\nFOUND\n";
    }
    return 0;
}

//            10
//5 6                 12 15 20
