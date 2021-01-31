#include<vector>
#include "ListNode.cpp"
using namespace std;
//12:38 to 12:50 a bit slow for an easy question
/*
Runtime: 40 ms, faster than 82.90% of C++ online submissions for Intersection of Two Linked Lists.
Memory Usage: 14.6 MB, less than 84.64% of C++ online submissions for Intersection of Two Linked Lists.
*/
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        auto a = headA;
        auto b = headB;
        if (a == nullptr || b == nullptr)
        {
            return nullptr;
        }
        int ac = 0;
        int bc = 0;
        while (a->next != nullptr)
        {
            a = a->next;
            ac++;
        }
        while (b->next != nullptr)
        {
            b = b->next;
            bc++;
        }
        if (a != b)
        {
            return nullptr;
        }
        a = headA;
        b = headB;
        if (ac != bc)
        {
            auto c = ac > bc ? a : b;
            int cc = abs(ac - bc);
            while (cc-- > 0)
            {
                c = c->next;
            }
            if (ac > bc)
            {
                a = c;
            }
            else
            {
                b = c;
            }
        }
        while (a != b)
        {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};