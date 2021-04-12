#include<bits/stdc++.h>

using namespace std;

#define MAX 4

typedef struct Node {
    int ver;
    //int weight=0;
    Node * next;
}node;

typedef struct LIST {
    node *head;
}List;

List *adj_list[MAX] = {0};

void insertNode(int s,int d) {
    cout<<'A'<<endl;
    node *src,*des,*temp;
    if(adj_list[s]->head == NULL) {
        cout<<'B'<<endl;
        src = new node();
        src->next = NULL;
        src->ver = s;
        adj_list[s]->head = src;
    }
    cout<<'C'<<endl;
    des = new node();
    des->next = NULL;
    des->ver = d;
    temp = adj_list[s]->head;
    cout<<'D'<<endl;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    cout<<'E'<<endl;
    temp->next = des;
}

void display() {
    node *temp;
    for(int i=0;i<MAX;i++) {
        temp = adj_list[i]->head;
        if(temp!=NULL) {
            cout<<"For vertex "<<i<<": ";
            while(temp!=NULL) {
                cout<<temp->ver<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
}

int main() {
    int c,s,d;
    for(int i=0;i<MAX;i++) {
        adj_list[i] = new List();
        adj_list[i]->head = NULL;
    }
    bool flag = true;
    while(flag) {
        cin>>s>>d;
        insertNode(s,d);
        cout<<"Do you want to continue?(0/1)";
        cin>>c;
        if(c==0) {
            flag = false;
        }
    }
    display();
    return 0;
}
