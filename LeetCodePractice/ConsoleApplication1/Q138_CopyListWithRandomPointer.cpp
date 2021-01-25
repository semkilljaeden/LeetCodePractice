#include<vector>
#include<unordered_map>
#include "NodeRandom.cpp"
using namespace std;
//4:12 to 4:32
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Copy List with Random Pointer.
Memory Usage: 11.8 MB, less than 11.19% of C++ online submissions for Copy List with Random Pointer.
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> index;
        unordered_map<Node*, int> index_map;
        auto new_head = clone(head, index, index_map);
        auto itr = new_head;
        while (head != nullptr)
        {
            if (head->random == nullptr)
            {
                itr->random = nullptr;
            }
            else
            {
                itr->random = index[index_map[head->random]];
            }
            head = head->next;
            itr = itr->next;
        }
        return new_head;
    }

    Node* clone(Node* head, vector<Node*>& index, unordered_map<Node*, int>& index_map)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node* nh = new Node(head->val);
        index_map[head] = index.size();
        index.push_back(nh);
        nh->next = clone(head->next, index, index_map);
        return nh;
    }
};