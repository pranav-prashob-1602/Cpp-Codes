#include <bits/stdc++.h>
using namespace std;


struct Node
{
        int data;
        Node *next;
};
void insert(Node **);
void display(Node *);
void merge(Node *, Node **);

int main()
{
    Node *first = NULL, *second = NULL;
    insert(&first);
    insert(&second);
    merge(first, &second);
    cout<<"\nMerged list is: ";
    display(first);

    return 0;
}
void insert(Node ** head_ref)
{
    int n,new_data;
    do{
            cout<<"\nEnter data :";
            cin>>new_data;
            Node* new_node = new Node();
            new_node->data = new_data;
            if(*head_ref == NULL) {
                (*head_ref) = new_node;
            }else {
                Node* ptr = new Node();
                ptr = *head_ref;
                while(ptr->next != NULL) {
                    ptr= ptr->next;
                }
                ptr->next  = new_node;
        }

        cout<<"Do you want to continue? (1/0)";
        cin>>n;
    }while(n==1);
}


void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void merge(Node *first, Node **second)
{
    Node *firstRef = first;
    while (firstRef->next != NULL)
    {
         firstRef = firstRef->next;
    }

    firstRef->next = *second;
}
