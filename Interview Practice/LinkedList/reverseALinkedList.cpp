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

ListNode *reverse(ListNode *head) {
    ListNode *prev=nullptr, *cur=head, *nxt=head->next;
    while(nxt!=nullptr) {
        cur->next=prev;
        prev=cur;
        cur=nxt;
        nxt=nxt->next;
    }
    cur->next=prev;
    return cur;
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

    ListNode *head = reverse(dummy->next);
    while (head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
