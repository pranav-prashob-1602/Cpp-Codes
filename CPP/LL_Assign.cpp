#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

static int k=0;
static int list_num = 0;

struct Node {
    int data;
   Node* next;
}*start[100],*ptr,*newNode,*save,*temp;

bool Empty_List(Node *np) {
    if(np == NULL) {
        return true;
    }
    return false;
}

Node* createNewNode(int n) {
    ptr = new Node;
    ptr->data = n;
    ptr->next = NULL;
    return ptr;
}

void createList(Node **np) {
    int n,new_data;
    cout<<"\n\nLINKED LIST CREATION --\n";
    do{
            cout<<"\nEnter data :\t";
            cin>>new_data;
            Node* new_node = createNewNode(new_data);
            if(Empty_List(*np)) {
                (*np) = new_node;
            }else {
                Node* ptr = new Node();
                ptr = *np;
                while(ptr->next != NULL) {
                    ptr= ptr->next;
                }
                ptr->next  = new_node;
        }
        cout<<"Do you want to continue? (1/0)\t";
        cin>>n;
    }while(n==1);
    cout<<"\n\n\t\tLINKED LIST CREATED!";
    getch();
}

int getList_Num() {
    int x;
    if(k==0) {
        cout<<"\n\n\t\tPLEASE CREATE A LINKED LIST FIRST...";
        getch();
        return -1;
    }
    cout<<"\n\nAVAILABLE LIST NUMBERS : 0 to "<<k<<"\n\nEnter the List Number :\t ";
    cin>>x;
    if(!(x>=0 && x<k)) {
        cout<<"\n\n\t\tINVALID INPUT";
        getch();
        return -1;
    }
    return x;
}

void insert_beg(Node **np) {
    int x;
    cout<<"\n\nEnter the value to be Inserted : ";
    cin>>x;
    ptr = createNewNode(x);
    if(Empty_List(*np)) {
            *np = ptr;
            return;
    }
    ptr->next = *np;
    *np = ptr;
}

void insertBEG() {
    list_num = getList_Num();
    if(list_num == -1)
        return;
    insert_beg(&start[list_num]);
    cout<<"\n\n\t\tNode Inserted Successfully!";
    getch();
}

void insert_end(Node **np) {
    int x;
    cout<<"\n\nEnter the value to be Inserted : ";
    cin>>x;
    ptr = createNewNode(x);
    if(Empty_List(*np)) {
        *np = ptr;
        return;
    }
    temp = *np;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = ptr;
}

void insertEND() {
    list_num = getList_Num();
    if(list_num == -1)
        return;
    insert_end(&start[list_num]);
    cout<<"\n\n\t\tNode Inserted Successfully!";
    getch();
}

int insert_after_val(Node ** np,int n) {
    int x;
    if(Empty_List(*np)) {
         return 0;
    }
    int flag = 0;
    temp = *np;
    while(temp != NULL) {
        if(temp->data == n) {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(!flag) {
        return flag;
    }
    cout<<"\n\nEnter the value to be Inserted : ";
    cin>>x;
    ptr = createNewNode(x);
    if(temp->next == NULL) {
        temp->next = ptr;
        return flag;
    }
    save = temp->next;
    temp->next = ptr;
    ptr->next = save;
    return flag;
}

void insertAFTERVAL() {
    list_num = getList_Num();
    if(list_num == -1)
        return;
    int n;
    cout<<"\n\nEnter the value after which Node should be inserted : ";
    cin>>n;
    int y = insert_after_val(&start[list_num],n);
    if(y==0) {
        cout<<"\n\n\t\tINVALID VALUE!!";
        getch();
        return;
    }
    cout<<"\n\n\t\tNode Inserted Successfully!";
    getch();
}

int insert_position(Node ** np,int n) {
    int x;
    if(Empty_List(*np)) {
         return 0;
    }
    int flag = 0;
    temp = *np;
    x=1;
    while(temp != NULL) {
        if(x == n-1) {
            flag = 1;
            break;
        }
        x++;
        temp = temp->next;
    }
    if(!flag) {
        return flag;
    }
    cout<<"\n\nEnter the value to be Inserted : ";
    cin>>x;
    ptr = createNewNode(x);
    if(temp->next == NULL) {
        temp->next = ptr;
        return flag;
    }
    save = temp->next;
    temp->next = ptr;
    ptr->next = save;
    return flag;
}

void insertPOSITION() {
    list_num = getList_Num();
    if(list_num == -1)
        return;
    int n;
    cout<<"\n\nEnter the position : ";
    cin>>n;
    int y = insert_position(&start[list_num],n);
    if(y==0) {
        cout<<"\n\n\t\tINVALID POSITION!!";
        getch();
        return;
    }
    cout<<"\n\n\t\tNode Inserted Successfully!";
    getch();
}

void Insert() {
    int x;
    system("CLS");
    cout<<"\n\nINSERT NODE MENU";
    cout<<"\n1 to Insert in the beginning";
    cout<<"\n2 to Insert in the end";
    cout<<"\n3 to Insert in a position";
    cout<<"\n4 to Insert after a certain element";
    cout<<"\n5 to Go to the Main Menu";
    cout<<"\n\nEnter your choice:\t";
    cin>>x;
    switch(x) {
        case 1:
            insertBEG();
            break;
        case 2:
            insertEND();
            break;
        case 3:
            insertPOSITION();
            break;
        case 4:
            insertAFTERVAL();
            break;
        case 5:
            return;
        default:
            cout<<"\n\n\t\tINVALID INPUT!!";
    }
}

int delete_beg(Node **np) {
    if(Empty_List(*np)) {
        cout<<"\n\n\t\tTHE LINKED LIST IS EMPTY!!";
        return -1;
    }
    ptr = *np;
    *np = ptr->next;
    delete ptr;
    return 1;
}

void deleteBEG() {
    list_num = getList_Num();
    if(list_num == -1)
        return;
    int x = delete_beg(&start[list_num]);
    if(x == 1){
        cout<<"\n\n\t\tNode Deleted Successfully!";
    }
    getch();
}

int delete_end(Node **np) {
    if(Empty_List(*np)) {
        cout<<"\n\n\t\tTHE LINKED LIST IS EMPTY!!";
        return -1;
    }
    ptr = *np;
    save = ptr;
    while(ptr->next != NULL) {
        save = ptr;
        ptr=ptr->next;
    }
    save->next = NULL;
    delete ptr;
    return 1;
}

void deleteEND() {
    list_num = getList_Num();
    if(list_num == -1)
        return;
    int x = delete_end(&start[list_num]);
    if(x == 1){
        cout<<"\n\n\t\tNode Deleted Successfully!";
    }
    getch();
}

int delete_position(Node ** np,int n) {
    int x;
    if(Empty_List(*np)) {
         return 0;
    }
    int flag = 0;
    temp = *np;
    save = temp;
    if(n==1) {
        *np = temp->next;
        temp->next = NULL;
        delete temp;
        return 1;
    }
    x=0;
    while(temp != NULL) {
        if(x == n-1) {
            flag = 1;
            break;
        }
        x++;
        save = temp;
        temp = temp->next;
    }
    if(!flag) {
        return flag;
    }
    save->next = temp->next;
    temp->next = NULL;
    delete temp;
    return flag;
}

void deletePOSITION() {
    list_num = getList_Num();
    if(list_num == -1)
        return;
    int n;
    cout<<"\n\nEnter the position : ";
    cin>>n;
    int y = delete_position(&start[list_num],n);
    if(y==0) {
        cout<<"\n\n\t\tINVALID POSITION!!";
        getch();
        return;
    }
    cout<<"\n\n\t\tNode Deleted Successfully!";
    getch();
}

int delete_value(Node ** np,int n) {
    int x;
    if(Empty_List(*np)) {
         return 0;
    }
    int flag = 0;
    temp = *np;
    save = temp;
    if(temp->data == n) {
        *np = temp->next;
        temp->next = NULL;
        delete temp;
        return 1;
    }
    while(temp != NULL) {
        if(temp->data == n) {
            flag = 1;
            break;
        }
        x++;
        save = temp;
        temp = temp->next;
    }
    if(!flag) {
        return flag;
    }
    save->next = temp->next;
    temp->next = NULL;
    delete temp;
    return flag;
}

void deleteVALUE() {
    list_num = getList_Num();
    if(list_num == -1)
        return;
    int n;
    cout<<"\n\nEnter value to be Deleted : ";
    cin>>n;
    int y = delete_value(&start[list_num],n);
    if(y==0) {
        cout<<"\n\n\t\tINVALID  VALUE!!";
        getch();
        return;
    }
    cout<<"\n\n\t\tNode Deleted Successfully!";
    getch();
}

void Delete() {
    int x;
    system("CLS");
    cout<<"\n\nDELETE NODE MENU";
    cout<<"\n1 to Delete the first node";
    cout<<"\n2 to Delete the last node";
    cout<<"\n3 to Delete the node at a position";
    cout<<"\n4 to Delete a node by value";
    cout<<"\n5 to Go to the Main Menu";
    cout<<"\n\nEnter your choice:\t";
    cin>>x;
    switch(x) {
        case 1:
            deleteBEG();
            break;
        case 2:
            deleteEND();
            break;
        case 3:
            deletePOSITION();
            break;
        case 4:
            deleteVALUE();
            break;
        case 5:
            return;
        default:
            cout<<"\n\n\t\tINVALID INPUT!!";
    }
}

void merge_half_split(Node* np, Node** first, Node** second)
{
    Node* ptr1;
    Node* ptr2;
    ptr2 = np;
    ptr1 = np->next;
    while (ptr1 != NULL) {
        ptr1 = ptr1->next;
        if (ptr1 != NULL) {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
    }
    *first = np;
    *second = ptr2->next;
    ptr2->next = NULL;
}


Node* merge_sort(Node* ptr1, Node* ptr2)
{
    Node* np = NULL;
    if (Empty_List(ptr1))
        return (ptr2);
    else if (Empty_List(ptr2))
        return (ptr1);
    if (ptr1->data <= ptr2->data) {
        np = ptr1;
        np->next = merge_sort(ptr1->next, ptr2);
    }else {
        np = ptr2;
        np->next = merge_sort(ptr1, ptr2->next);
    }
    return (np);
}

void merge_LIST_SORT(Node** np)
{
    Node* head = *np;
    Node* ptr1;
    Node* ptr2;
    if (Empty_List(head) || Empty_List(head->next)) {
        return;
    }
    merge_half_split(head, &ptr1, &ptr2);
    merge_LIST_SORT(&ptr1);
    merge_LIST_SORT(&ptr2);
    *np = merge_sort(ptr1, ptr2);
}

void merge_LISTS(Node *ptr1,Node *ptr2) {
    Node *temp = ptr1;
    while (temp->next != NULL)
    {
         temp = temp->next;
    }
    Node *temp1 = ptr2;
    while(temp1 != NULL) {
        Node *np = createNewNode(temp1->data);
        temp->next = np;
        temp = temp->next;
        temp1 = temp1->next;
    }
}

void Merge() {
    if(k<=1) {
        cout<<"\n\n\t\tMINIMUM TWO LISTS ARE REQUIRED!!";
        getch();
        return;
    }
    int a = getList_Num();
    if(a==-1)
        return;
    int b = getList_Num();
    if(b==-1)
        return;
    if(a==b) {
        cout<<"\n\n\t\tCANNOT PERFORM IT ON THE SAME LISTS!!";
        getch();
        return;
    }
    merge_LISTS(start[a],start[b]);
    merge_LIST_SORT(&start[a]);
    cout<<"\n\n\t\tMERGE SORT ON LINKED LIST "<<a<<" AND "<<b<<" IS SUCCESSFUL!!";
    getch();
}

void traverse_List(Node *ptr) {
    while(ptr != NULL) {
        cout<<"->"<<ptr->data;
        ptr = ptr->next;
    }
    cout<<"->NULL"<<endl;
    getch();
}

void Display() {
    list_num = getList_Num();
    if(list_num == -1)
        return;
    cout<<"\n\nLinked List "<<list_num<<" : ";
    traverse_List(start[list_num]);
}

int main() {
    int m,n;
    do {
        system("CLS");
        cout<<"\n\nMENU";
        cout<<"\n1 to Create a linked list";
        cout<<"\n2 to Insert elements";
        cout<<"\n3 to Delete an element";
        cout<<"\n4 to Merge two linked lists";
        cout<<"\n5 to Display the list";
        cout<<"\n6 to Exit";
        cout<<"\n\nEnter your choice:\t";
        cin>>n;
        switch(n) {
            case 1:
                createList(&start[k]);
                k++;
                break;
            case 2:
                Insert();
                break;
            case 3:
                Delete();
                break;
            case 4:
                Merge();
                break;
            case 5:
                Display();
                break;
            case 6:
                cout<<"\n\n\t\tHAVE A GOOD DAY!!\n\n";
                break;
            default:
                cout<<"\n\n\t\tINVALID INPUT!!";
                getch();
        }
    }while(n != 6);
  	return 0;
}
