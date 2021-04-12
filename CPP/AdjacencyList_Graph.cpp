#include<bits/stdc++.h>

using namespace std;

#define MAX 4

typedef struct Node {
    int ver;
    //int weight=0;
    Node * next;
}node;

class List {
    node *head;
public:
    void insertNode(int s,int d);
    void display(int i);
};

void List::insertNode(int s,int d) {
    node *src,*des,*temp;
    if(this->head == NULL) {
        src = new node();
        src->next = NULL;
        src->ver = s;
        this->head = src;
    }
    des = new node();
    des->next = NULL;
    des->ver = d;
    temp = this->head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next = des;
}

void List::display(int i) {
    node *temp;
    temp = this->head;
    if(temp!=NULL) {
        cout<<"For vertex "<<i<<": ";
        while(temp!=NULL) {
            cout<<temp->ver<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

int main() {
    int c,s,d;
    List *adj_list[MAX];
    bool flag = true;
    while(flag) {
        cin>>s>>d;
        cout<<endl;
        adj_list[s]->insertNode(s,d);
        cout<<"Do you want to continue?(0/1)";
        cin>>s;
        if(c==0) {
            flag = false;
        }
    }
    for(int i=0;i<MAX;i++) {
        adj_list[i]->display(i);
    }
    return 0;
}
