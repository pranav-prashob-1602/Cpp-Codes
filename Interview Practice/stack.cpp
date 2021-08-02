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

class Stack {
    Node* top;
public:

    Stack() {
        top=NULL;
    }

    void push(int val);
    void pop();
    void display();
};

void Stack::push(int val) {
    Node* ptr=new Node(val);
    ptr->next=this->top;
    this->top=ptr;
}

void Stack::pop() {
    if(this->top==NULL) {
        cout<<"Underflow"<<endll;
        return;
    }
    Node* ptr=top;
    top=top->next;
    ptr->next=NULL;
    delete(ptr);
}

void Stack::display() {
    cout<<"Stack"<<endll;
    Node* ptr=this->top;
    while(ptr!=NULL) {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endll;
}

int main() {
    Stack *st=new Stack();
    st->push(5);
    st->display();
    st->push(6);
    st->display();
    st->push(7);
    st->display();
    st->push(8);
    st->display();
    st->pop();
    st->display();
    st->pop();
    st->display();
    return 0;
}
