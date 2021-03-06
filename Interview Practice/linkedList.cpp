#include<bits/stdc++.h>

#define endll '\n'

using namespace std;

class Node {
    int val;
public:
    Node* next;
    Node() {
        val=0;
        next=NULL;
    }

    Node(int val) {
        this->val=val;
    }

    void setData(int val) {
        this->val=val;
    }

    void insertNode(Node** head, int val);
    void deleteNode(Node** head, int val);
    void display(Node* head);
    int length();
    int length(Node* head);
    bool searchNode(Node* head, int val);
    bool recSearchNode(Node* head, int val);
    int midNode(Node* head);
    int countOcc(Node* head, int val);
    int recCountOcc(Node* head, int val);
    bool detectLoop(Node* head);
    int countLoopNodes(Node* head);
    bool isPalin(Node* head);
    bool isPalin(Node** left, Node* right);
    void removeDupsInSorted(Node* head);
    void removeDupsInUnsorted(Node* head);
    Node* sortedIntersect(Node* a, Node* b);
    int getIntersection(Node* a, Node* b);
    void reverseList(Node** head);

};

void Node::insertNode(Node** head, int val) {
    Node* ptr = new Node(val);
    ptr->next=*head;
    *head=ptr;
}

void Node::deleteNode(Node** head, int val) {
    Node* ptr = *head;
    Node* temp=NULL;
    while(ptr!=NULL && ptr->val!=val) {
        temp=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL) {
        cout<<"Value not found"<<endll;
        return;
    }
    if(temp==NULL) {
        *head=ptr->next;
        ptr->next=NULL;
        delete(ptr);
        return;
    }
    temp->next=ptr->next;
    ptr->next=NULL;
    delete(ptr);
}

void Node::display(Node* head) {
    cout<<"LinkedList:"<<endll;
    Node* ptr=head;
    while(ptr!=NULL) {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endll;
}

int Node::length() {
    Node* ptr=this;
    int len=0;
    while(ptr!=NULL) {
        len++;
        ptr=ptr->next;
    }
    return len;
}

int Node::length(Node* head) {
    if(head==NULL) {
        return 0;
    }
    return 1+length(head->next);
}

bool Node::searchNode(Node* head, int val) {
    Node* ptr=head;
    while(ptr!=NULL) {
        if(ptr->val==val) {
            return true;
        }
        ptr=ptr->next;
    }
    return false;
}

bool Node::recSearchNode(Node* head, int val) {
    if(head==NULL) {
        return false;
    }
    if(head->val==val) {
        return true;
    }
    return recSearchNode(head->next, val);
}

int Node::midNode(Node* head) {
    Node* slow_ptr=head;
    Node* fast_ptr=head;
    while(fast_ptr!=NULL && fast_ptr->next!=NULL) {
        fast_ptr=fast_ptr->next->next;
        slow_ptr=slow_ptr->next;
    }
    if(slow_ptr==NULL) {
        return -1;
    }
    return slow_ptr->val;
}

int Node::countOcc(Node* head, int val) {
    Node* ptr=head;
    int cnt=0;
    while(ptr!=NULL) {
        cnt+=(ptr->val==val);
        ptr=ptr->next;
    }
    return cnt;
}

int Node::recCountOcc(Node* head, int val) {
    if(head==NULL) {
        return 0;
    }
    return (head->val==val)+recCountOcc(head->next, val);
}

bool Node::detectLoop(Node* head) {
    Node* slow_ptr=head;
    Node* fast_ptr=head;
    while(slow_ptr!=NULL && fast_ptr!=NULL && fast_ptr->next!=NULL) {
        fast_ptr=fast_ptr->next->next;
        slow_ptr=slow_ptr->next;
        if(slow_ptr==fast_ptr) {
            return true;
        }
    }
    return false;
}

int countNodes(Node* ptr) {
    int cnt=1;
    Node* temp=ptr;
    while(temp->next!=ptr) {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

int Node::countLoopNodes(Node* head) {
    Node* slow_ptr=head;
    Node* fast_ptr=head;
    while(slow_ptr!=NULL && fast_ptr!=NULL && fast_ptr->next!=NULL) {
        fast_ptr=fast_ptr->next->next;
        slow_ptr=slow_ptr->next;
        if(slow_ptr==fast_ptr) {
            return countNodes(slow_ptr);
        }
    }
    return 0;
}

bool Node::isPalin(Node* head) {
    stack<int> st;
    Node* ptr=head;
    while(ptr!=NULL) {
        st.push(ptr->val);
        ptr=ptr->next;
    }
    ptr=head;
    while(st.size()>0) {
        if(st.top()!=ptr->val) {
            return false;
        }
        st.pop();
        ptr=ptr->next;
    }
    return true;
}

bool Node::isPalin(Node** left, Node* right) {
    if(right==NULL) {
        return true;
    }

    bool temp1=isPalin(left, right->next);
    if(temp1==false) {
        return false;
    }
    bool temp2=((*left)->val==right->val);
    (*left)=(*left)->next;
    return temp2;
}

void Node::removeDupsInSorted(Node* head) {
    Node* ptr=head;
    Node* temp;
    while(ptr->next!=NULL) {
        if(ptr->val==ptr->next->val) {
            temp=ptr->next->next;
            delete(ptr->next);
            ptr->next=temp;
        }else {
            ptr=ptr->next;
        }
    }
}

void Node::removeDupsInUnsorted(Node* head) {
    Node* ptr=head;
    Node* temp=NULL;
    unordered_map<int, int> mp;
    while(ptr!=NULL) {
        if(mp[ptr->val]>0) {
            temp->next=ptr->next;
            ptr->next=NULL;
            delete(ptr);
            ptr=temp;
        }
        mp[ptr->val]++;
        temp=ptr;
        ptr=ptr->next;
    }
}

Node* Node::sortedIntersect(Node* a, Node* b) {
    Node* head=new Node();
    Node* ptr=head;
    Node* ptr1=a, *ptr2=b;
    while(ptr1!=NULL && ptr2!=NULL) {
        if(ptr1->val==ptr2->val) {
            Node* c=new Node(ptr1->val);
            ptr->next=c;
            ptr=ptr->next;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }else if(ptr1->val>ptr2->val) {
            ptr2=ptr2->next;
        }else {
            ptr1=ptr1->next;
        }
    }
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete(temp);
    return head;
}

Node* getIntersectionValue(int d, Node* a, Node* b) {
    Node* ptr1=a;
    Node* ptr2=b;
    for(int i=0;i<d;i++) {
        if(ptr1==NULL) {
            return NULL;
        }
        ptr1=ptr1->next;
    }
    while(ptr1!=NULL && ptr2!=NULL) {
        if(ptr1==ptr2) {
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return NULL;
}

int Node::getIntersection(Node* a, Node* b) {
    int n=a->length();
    int m=b->length();
    int d=abs(a-b);
    if(n>m) {
        Node* ptr = getIntersectionValue(d, a, b);
        return ptr==NULL ? -1 : ptr->val;
    }else {
        Node* ptr = getIntersectionValue(d, b, a);
        return ptr==NULL ? -1 : ptr->val;
    }
}

void Node::reverseList(Node** head) {
    Node* ptr=*head;
    Node* prev=NULL, *nxt;
    while(ptr!=NULL) {
        nxt=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=nxt;
    }
    *head=prev;
}

int main() {
    Node* head=new Node(5);
    head->insertNode(&head, 11);
    head->insertNode(&head, 2);
    head->insertNode(&head, 4);
    head->insertNode(&head, 9);
    head->display(head);
    head->deleteNode(&head, 5);
    head->display(head);
    head->deleteNode(&head, 8);
    head->display(head);
    head->insertNode(&head, 4);
    head->insertNode(&head, 11);
    //head->insertNode(&head, 11);
    head->display(head);
    cout<<head->length()<<endll;
    cout<<head->length(head)<<endll;
    if(head->searchNode(head, 11)) {
        cout<<"Found"<<endll;
    }else {
        cout<<"Not Found"<<endll;
    }
    if(head->recSearchNode(head, 5)) {
        cout<<"Found"<<endll;
    }else {
        cout<<"Not Found"<<endll;
    }
    cout<<head->midNode(head)<<endll;
    cout<<head->countOcc(head, 3)<<endll;
    cout<<head->recCountOcc(head, 3)<<endll;
    head->display(head);
    head->next->next->next->next->next=head;
    if(head->detectLoop(head)) {
        cout<<"Loop found"<<endll;
        cout<<head->countLoopNodes(head)<<endll;
    }else {
        cout<<"Loop not found"<<endll;
    }
    head->next->next->next->next->next=NULL;
    if(head->isPalin(head)) {
        cout<<"Palindrome"<<endll;
    }else {
        cout<<"Not palindrome"<<endll;
    }
    head->display(head);
    if(head->isPalin(&head, head)) {
        cout<<"Palindrome"<<endll;
    }else {
        cout<<"Not palindrome"<<endll;
    }
    head->display(head);
    head->removeDupsInSorted(head);
    head->display(head);
    head->removeDupsInUnsorted(head);
    head->display(head);
    Node* a=new Node(9);
    a->insertNode(&a, 6);
    a->insertNode(&a, 5);
    a->insertNode(&a, 4);
    a->insertNode(&a, 2);
    Node* b=new Node(9);
    b->insertNode(&b, 6);
    b->insertNode(&b, 4);
    b->insertNode(&b, 3);
    b->insertNode(&b, 2);
    a->display(a);
    b->display(b);
    cout<<"Intersect ";
    Node* temp=a->sortedIntersect(a, b);
    temp->display(temp);
    head->display(head);
    head->reverseList(&head);
    head->display(head);
    return 0;
}
