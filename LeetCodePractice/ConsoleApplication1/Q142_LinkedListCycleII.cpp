#include<vector>
#include "ListNode.cpp"
#include<unordered_set>
using namespace std;

//9:37 to 9;49, not the best solution, read the solution

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> set;
        while (head != nullptr)
        {
            if (set.find(head) != set.end())
            {
                return head;
            }
            set.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};