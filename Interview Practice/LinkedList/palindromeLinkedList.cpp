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

bool isPalindrome(ListNode *head) {
    stack<int> st;
    ListNode *temp = head;
    while(temp!=nullptr) {
        st.push(temp->val);
        temp=temp->next;
    }
    temp=head;
    while(!st.empty()) {
        if(temp->val!=st.top()) {
            return false;
        }
        st.pop();
        temp=temp->next;
    }
    return true;
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

    cout << (boolalpha) << isPalindrome(dummy->next) << endl;

    return 0;
}
