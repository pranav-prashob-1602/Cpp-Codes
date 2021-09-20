#include <bits/stdc++.h>
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

void fold(ListNode *head)
{
    ListNode *ptr1=head,*ptr2=head;
    while(ptr2!=nullptr && ptr2->next!=nullptr) {
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }
    ListNode* head2=ptr1;
    stack<int> st;
    while(ptr1!=nullptr) {
        st.push(ptr1->val);
        ptr1=ptr1->next;
    }
    ptr1=head2;
    while(!st.empty()) {
        ptr1->val = st.top();
        st.pop();
        ptr1=ptr1->next;
    }
    vector<int> v;
    ptr1=head, ptr2=head2;
    while(ptr1!=head2 && ptr2!=nullptr) {
        v.push_back(ptr1->val);
        v.push_back(ptr2->val);
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    if(ptr2!=nullptr) {
        v.push_back(ptr2->val);
    }
    ptr1=head;
    for(auto& value  : v) {
        ptr1->val = value;
        ptr1=ptr1->next;
    }
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
    fold(head);
    printList(head);

    return 0;
}
