#include<vector>
#include "ListNode.cpp"

using namespace std;
//10mins?
/*
Runtime: 24 ms, faster than 83.94% of C++ online submissions for Remove Linked List Elements.
Memory Usage: 15 MB, less than 77.32% of C++ online submissions for Remove Linked List Elements.
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode x(0, head);
        auto p = &x;
        while (head != nullptr)
        {
            if (head->val == val)
            {
                p->next = head->next;
                head->next = nullptr;
                head = p->next;
            }
            else
            {
                p = p->next;
                head = (p == nullptr ? nullptr : p->next);
            }
        }
        return x.next;
    }
};

