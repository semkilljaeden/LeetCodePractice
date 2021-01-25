#include<vector>
#include "ListNode.cpp"
using namespace std;
//9:54 10:28, used debugger
/*
Runtime: 44 ms, faster than 72.87% of C++ online submissions for Insertion Sort List.
Memory Usage: 9.6 MB, less than 96.23% of C++ online submissions for Insertion Sort List.

*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        auto cur = head->next;
        auto pre_cur = head;
        ListNode new_pre(0, head);
        while (cur != nullptr)
        {
            //remove
            pre_cur->next = cur->next;
            auto next = cur->next;
            cur->next = nullptr;
            //locate
            auto pre_new = &new_pre;
            auto new_head = pre_new->next;
            while (new_head != nullptr && new_head->val < cur->val)
            {
                new_head = new_head->next;
                pre_new = pre_new->next;
            }
            auto y = pre_new->next;
            pre_new->next = cur;
            cur->next = y;
            if (pre_cur->next == cur)
            {
                pre_cur = cur;
            }
            cur = next;

        }
        return new_pre.next;
    }
};