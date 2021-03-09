#include "LCHeader.h"
#include "ListNode.cpp"
//7:49 8:07

/*
Runtime: 16 ms, faster than 99.31% of C++ online submissions for Add Two Numbers II.
Memory Usage: 71.1 MB, less than 71.82% of C++ online submissions for Add Two Numbers II.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        int l1_size = 0;
        while (p != nullptr) {
            p = p->next;
            l1_size++;
        }
        p = l2;
        int l2_size = 0;
        while (p != nullptr) {
            p = p->next;
            l2_size++;
        }
        auto left = l1;
        auto right = l2;
        if (l1_size > l2_size) {
            right = append(l1_size - l2_size, l2);
        }
        else if (l2_size > l1_size) {
            left = append(l2_size - l1_size, l1);
        }
        auto r = rec(left, right);
        auto result = r.second;
        if (r.first == 1) {
            auto root = new ListNode(1);
            root->next = result;
            result = root;
        }
        while (right != l2) {
            auto tmp = right->next;
            delete right;
            right = tmp;
        }
        while (left != l1) {
            auto tmp = left->next;
            delete left;
            left = tmp;
        }
        return result;
    }

    pair<int, ListNode*> rec(ListNode* left, ListNode* right) {
        if (left == nullptr) {
            return make_pair(0, nullptr);
        }
        auto next = rec(left->next, right->next);
        int value = left->val + right->val + next.first;
        int carry = value / 10;
        value %= 10;
        auto node = new ListNode(value);
        node->next = next.second;
        return make_pair(carry, node);
    }


    ListNode* append(int count, ListNode* node) {
        if (count == 0) {
            return node;
        }
        auto n = new ListNode(0);
        auto root = n;
        while (count > 1) {
            auto tmp = new ListNode(0);
            n->next = tmp;
            n = tmp;
            count--;
        }
        n->next = node;
        return root;
    }
};