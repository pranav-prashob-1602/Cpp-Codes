#include<iostream>

using namespace std;

struct Node {
    int data;
   Node* next;
}*start,*ptr,*newNode,*save;

Node * createNewNode(int n) {
    ptr = new Node;
    ptr->data = n;
    ptr->next = NULL;
    return ptr;
}

void insert_beg(Node *np) {
    if(start == NULL) {
            start = np;
            return;
    }
    np->next = start;
    start = np;
}

void insert_end(Node *np) {
    if(start == NULL) {
        start = np;
        return;
    }
    ptr = start;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = np;
}

/*
    The insert_mid() takes two arguments:
    A new Node which is to be inserted and the data of the node, next to which the new Node is to be inserted
*/
int insert_mid(Node * np, int x) {
    if(start == NULL) {
        start = np;
        return 1;
    }
    int flag = 0;
    ptr = start;
    while(ptr != NULL) {
        if(ptr->data == x) {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if(!flag) {
        return flag;
    }
    if(ptr->next == NULL) {
        ptr->next = np;
        return flag;
    }
    save = ptr->next;
    ptr->next = np;
    np->next = save;
    return flag;
}

/*void deleteNode(int x) {
    if(start == NULL) {
        return;
    }
    ptr = start;
    if(ptr->data == x) {
        start = start->next;
        delete ptr;
        return;
    }
    ptr = start->next;
    save  = start;
    while(ptr != NULL) {
        if(ptr->data == x) {
            break;
        }
        save = ptr;
        ptr = ptr->next;
    }
    save->next = ptr->next;
    ptr->next = NULL;
    delete ptr;
}*/

int deleteNode(int x) {
    if(start == NULL) {
        return 0;
    }
  	int flag =0;
    ptr = start;
    if(ptr->data == x) {
        start = start->next;
        delete ptr;
		flag =1;
    }
    ptr = start->next;
    save  = start;
    while(ptr != NULL) {
        if(ptr->data == x) {
            save->next = ptr->next;
    		ptr->next = NULL;
          	flag =1;
    		delete ptr;
        }
        save = ptr;
        ptr = ptr->next;
    }
    return flag;
}

Node* reverseList(Node *np) {
    if(np==NULL)
        return NULL;
    reverseList(np->next);
    cout<<np->data<<" ";
}

void traverse() {
    if(start == NULL)
        return;
    ptr = start;
    cout<<"\n";
    while(ptr!=NULL) {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main() {
    /*int x;
    newNode = createNewNode(5);
    insert_beg(newNode);
    newNode = createNewNode(8);
    insert_beg(newNode);
    newNode = createNewNode(10);
    insert_beg(newNode);
    newNode = createNewNode(2);
    insert_end(newNode);
    newNode = createNewNode(1);
    insert_end(newNode);
    traverse();
    newNode = createNewNode(9);
    x = insert_mid(newNode,10);
    traverse();
    newNode = createNewNode(4);
    x = insert_mid(newNode,5);
    traverse();
    newNode = createNewNode(0);
    x = insert_mid(newNode,1);
    traverse();
     newNode = createNewNode(-7);
    insert_end(newNode);
    traverse();
    deleteNode(10);
    traverse();
    deleteNode(5);
    traverse();
    deleteNode(0);
    traverse();
    deleteNode(-7);
    traverse();
    cout<<"\n";
    reverseList(start);
    */
    int n,x;
  	while(n--) {
      	cin>>x;
    	newNode = createNewNode(x);
    	insert_end(newNode);
    }
  	cin>>x;
  	if(!deleteNode(x)) {
    	cout<<"Invalid Node!\n";
    }
  	cout<<"Linked List : ";
  	traverse();
  	return 0;
}
