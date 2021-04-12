#include<bits/stdc++.h>

/*

shinchanCoder Here!!

*/

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

#define mod 1000000007

typedef struct node {
    int data;
    node *next;
}Node;

int Hash(int key) {
    return key%10;
}

void sortedInsert(Node** ptr,int key) {
    Node *temp = new Node();
    temp->data = key;
    temp->next = NULL;
    if(*ptr == NULL) {
        *ptr = temp;
        return;
    }
    Node* p = *ptr;
    Node* q;
    q = p;
    while(p!=NULL && p->data<key) {
        q = p;
        p = p->next;
    }
    if(p==*ptr) {
        temp->next = *ptr;
        *ptr=temp;
        return;
    }
    temp->next = p;
    q->next = temp;
}

void Insert(Node *ht[],int key) {
    int ind = Hash(key);
    sortedInsert(&ht[ind],key);
}

Node* searchNode(Node *p,int key) {
    while(p!=NULL) {
        if(p->data == key) {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *ht[10];
    for(int i=0;i<10;i++) {
        ht[i] = NULL;
    }
    Insert(ht,12);
    Insert(ht,42);
    Insert(ht,22);
    Insert(ht,52);
    Insert(ht,2);
    int key;
    cout<<"Enter the key value you want to search"<<endl;
    cin>>key;
    Node *temp = searchNode(ht[Hash(key)],key);
    if(temp!=NULL) {
        cout<<"YES";
    }else {
        cout<<"NO";
    }
    /*Node *temp = ht[2];
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }*/
    return 0;
}
