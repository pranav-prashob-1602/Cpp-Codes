#include<bits/stdc++.h>

#define endll '\n'

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node() {
        val=0;
        next=NULL;
    }

    Node(int val) {
        this->val=val;
        next=NULL;
    }
};

class Queue {
    Node* frnt,*rear;
public:

    Queue() {
        frnt=NULL;
        rear=NULL;
    }

    void enqueue(int val);
    void dequeue();
    void display();
};

void Queue::enqueue(int val) {
    Node* ptr=new Node(val);
    if(frnt==NULL) {
        rear=ptr;
        frnt=ptr;
        return;
    }
    rear->next=ptr;
    rear=rear->next;
}

void Queue::dequeue() {
    if(frnt==NULL) {
        cout<<"Underflow"<<endll;
        return;
    }
    Node* ptr=frnt;
    frnt=frnt->next;
    ptr->next=NULL;
    delete(ptr);
    if(frnt==NULL) {
        rear=NULL;
    }
}

void Queue::display() {
    Node* ptr=frnt;
    cout<<"Queue"<<endll;
    while(ptr!=NULL) {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endll;
}

int main() {
    Queue *q=new Queue();
    q->enqueue(10);
    q->display();
    q->enqueue(11);
    q->enqueue(15);
    q->display();
    q->dequeue();
    q->display();
    return 0;
}
