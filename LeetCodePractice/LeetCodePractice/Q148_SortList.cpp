#include<vector>
#include "ListNode.cpp"
using namespace std;
//11:52 12:34 TLE for quick sort
//1:11 merge sort
/*
Runtime: 76 ms, faster than 99.32% of C++ online submissions for Sort List.
Memory Usage: 29.1 MB, less than 95.33% of C++ online submissions for Sort List.

*/
class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
        {
            return head;
        }
        auto mid = getMid(head);
        if (head == mid)
        {
            return head;
        }
        auto left = sortList(head);
        auto right = sortList(mid);
        ListNode dum(0, nullptr);
        auto itr = &dum;
        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                itr->next = left;
                left = left->next;
            }
            else
            {
                itr->next = right;
                right = right->next;

            }
            itr = itr->next;
            itr->next = nullptr;
        }
        while (left != nullptr)
        {
            itr->next = left;
            left = left->next;
            itr = itr->next;
            itr->next = nullptr;
        }
        while (right != nullptr)
        {
            itr->next = right;
            right = right->next;
            itr = itr->next;
            itr->next = nullptr;
        }
        return dum.next;
    }

    ListNode* getMid(ListNode* head)
    {
        ListNode* mid = head;
        ListNode* fast = head;
        ListNode dum(0, head);
        auto prev = &dum;
        if (head->next == nullptr)
        {
            return head;
        }
        if (head->next->next == nullptr)
        {
            mid = head->next;
            head->next = nullptr;
            return mid;
        }
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            mid = mid->next;
            prev = prev->next;
        }
        prev->next = nullptr;
        return mid;
    }

};






class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* tail = nullptr;
        return sort(head, tail);
    }

    ListNode* sort(ListNode* head, ListNode*& tail)
    {
        if (head == nullptr || head->next == nullptr)
        {
            tail = head;
            return head;
        }
        ListNode leftNode(0, nullptr);
        auto left = &leftNode;
        ListNode pseudohead(0, head->next);
        auto phead = &pseudohead;
        auto right = head;
        auto itr = head->next;
        right->next = nullptr;
        auto leftItr = left;
        auto rightItr = right;
        while (itr != nullptr)
        {
            //extract
            auto node = itr;
            phead->next = node->next;
            node->next = nullptr;
            itr = phead->next;
            if (node->val < head->val)
            {
                leftItr->next = node;
                leftItr = leftItr->next;
            }
            else
            {
                rightItr->next = node;
                rightItr = rightItr->next;
            }
        }
        ListNode* left_tail = nullptr;
        ListNode* right_tail = nullptr;
        auto ll = sort(left->next, left_tail);
        auto rr = sort(right->next, right_tail);
        if (ll == nullptr)
        {
            tail = right_tail;
            right->next = rr;
            return right;
        }
        left_tail->next = right;
        right->next = rr;
        tail = right_tail != nullptr ? right_tail : left_tail;
        if (rr == nullptr)
        {
            tail = right;
        }
        return ll;
    }
};