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

void unfold(ListNode *head) {
    ListNode* head1 = new ListNode(-1);
    ListNode* head2 = new ListNode(-1);
    ListNode* ptr = head;
    ListNode* temp = head1;
    int cnt=1;
    while(ptr!=nullptr) {
        if(cnt%2) {
            temp->next = new ListNode(ptr->val);
            temp=temp->next;
        }else {
            ListNode* ptr2 = new ListNode(ptr->val);
            ptr2->next = head2;
            head2=ptr2;
            if(cnt==2) {
                head2->next = nullptr;
            }
        }
        cnt++;
        ptr=ptr->next;
    }
    temp->next = head2;
    head1=head1->next;
    *head=*head1;
}


int main()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = dummy->next;
    unfold(head);
    printList(head);

    return 0;
}
