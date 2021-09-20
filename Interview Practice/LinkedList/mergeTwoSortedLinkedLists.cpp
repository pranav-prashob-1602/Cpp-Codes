#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head=new ListNode(-1);
    ListNode *ptr=head;
    while(l1!=nullptr && l2!=nullptr) {
        if(l1->val<l2->val) {
            ptr->next = new ListNode(l1->val);
            l1=l1->next;
        }else {
            ptr->next = new ListNode(l2->val);
            l2=l2->next;
        }
        ptr=ptr->next;
    }
    while(l1!=nullptr) {
        ptr->next=new ListNode(l1->val);
        l1=l1->next;
        ptr=ptr->next;
    }
    while(l2!=nullptr) {
        ptr->next=new ListNode(l2->val);
        l2=l2->next;
        ptr=ptr->next;
    }
    head=head->next;
    return head;
}
void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int main()
{
    int n, m;
    cin >> n ;
    ListNode *h1 = createList(n);
    cin >> m;
    ListNode *h2 = createList(m);

    ListNode *head = mergeTwoLists(h1, h2);
    printList(head);

    return 0;
}
