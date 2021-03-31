#include "LCHeader.h"
#include "ListNode.cpp"


class Solution {//12:14 12:23
public:
    ListNode* h;
    ListNode* p;
    void reorderList(ListNode* head) {
        ListNode dummy;
        p = &dummy;
        h = head;
        rec(head);
    }

    void rec(ListNode* cur) {
        if (cur == nullptr) {
            return;
        }
        rec(cur->next);
        if (p == nullptr) {
            return;
        }
        if (cur == h) {
            p->next = cur;
            cur->next = nullptr;
            p = nullptr;
        }
        else if (h->next == cur) {
            p->next = h;
            cur->next = nullptr;
            p = nullptr;
        }
        else {
            p->next = h;
            h = h->next;
            p = p->next;
            p->next = cur;
            p = p->next;
            p->next = nullptr;
        }
    }
};