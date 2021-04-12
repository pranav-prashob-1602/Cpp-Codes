// Program to Implement the concept of Josephus Game using Circular Linked List

#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
}*head,*ptr,*temp,*save;

Node * createNode(int x) {
    Node * temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void insertNode(int n) {
    for(int i=1;i<=n;i++) {
        Node * ptr = createNode(i);
        if(head == NULL) {
            head = ptr;
            save = ptr;
            continue;
        }
        save->next = ptr;
        save = save->next;
        ptr->next = head;
    }
}
/*
    getJosephusPos function takes a variable m, which is no. of people to be skipped after every kill,
    it returns the node containing the last survivor
*/
Node * getJosephusPos(int m) {
    Node * n1 = head, *n2 = head;
    while(n1->next != n1) {
        int count = 0;
        while(count != m) {
            n2 = n1;
            n1 = n1->next;
            count++;
        }
        n2->next = n1->next;
        cout<<n1->data<<" is killed!\n";
        delete(n1);
        n1 = n2->next;
    }
    return n1;
}

int main() {
    int N,M;
    cout<<"\n\nEnter the Number of People : ";
    cin>>N;
    insertNode(N);
    cout<<"\n\nEnter the Number of People to be skipped : ";
    cin>>M;
    Node * ptr = getJosephusPos(M);
    cout<<"\n\nThe Survivor is --> "<<ptr->data;
    return 0;
}
