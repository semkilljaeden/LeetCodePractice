#include "LCHeader.h"
#include "ListNode.cpp"
//12:31 1:04 with debugger
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode();
        dummy->next = head;
        auto h = dummy;
        auto tail = dummy;
        while (h != nullptr) {
            for (int i = 0; i < k; i++) {
                if (h == nullptr) {
                    auto result = dummy->next;
                    delete dummy;
                    return result;
                }
                h = h->next;
            }
            if (h == nullptr) {
                break;
            }
            reverse(tail, h);
            tail = h;
        }
        auto result = dummy->next;
        delete dummy;
        return result;
    }
    void reverse(ListNode* tail, ListNode*& head) {
        ListNode* next = head->next;
        ListNode*& h = tail->next;
        head->next = nullptr;
        rev(tail->next, h, head);
        tail->next = h;
        head->next = next;
    }

    void rev(ListNode* node, ListNode*& head, ListNode*& tail) {
        if (node->next == nullptr) {
            head = node;
            tail = node;
            return;
        }
        rev(node->next, head, tail);
        node->next = nullptr;
        tail->next = node;
        tail = node;
        return;
    }
};