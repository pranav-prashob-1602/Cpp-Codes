#include<bits/stdc++.h>

using namespace std;

static int n,e;

void insertEdge(int cpt_list[],int x,int s,int d) {
    int k=n+2;
    for(int i=1;i<=s;i++) {
        k = max(k,cpt_list[i]);
    }
    int i;
    for(i=k;i<x;i++) {
        if(cpt_list[i]==0) {
            cpt_list[i]=s;
            break;
        }
    }
    for(int j=s)
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
    int T,s,d;
    cout<<"Enter the number of vertices and edges : ";
    cin>>n>>e;
    int list_size = n+e+2;
    int cpt_list[list_size] = {0};
    T=n;
    while(T--) {
        cin>>s>>d
        insertNode(cpt_list,list_size,s,d);
    }
    display();
    return 0;
}
