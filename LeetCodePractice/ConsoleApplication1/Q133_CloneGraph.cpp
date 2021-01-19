#include<vector>
#include "GraphNode.cpp"
#include<unordered_map>
using namespace std;
//10:33 to 10:58, too sometimes to research c++ syntax, should be less than 15mins
/*
Runtime: 4 ms, faster than 99.44% of C++ online submissions for Clone Graph.
Memory Usage: 9 MB, less than 62.20% of C++ online submissions for Clone Graph.
*/

class Solution {
public:
    unordered_map<int, Node*> map;
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
        {
            return node;
        }
        if (map.find(node->val) != map.end())
        {
            return map[node->val];
        }
        Node* n = new Node(node->val);
        map[n->val] = n;
        for (auto x : node->neighbors)
        {
            n->neighbors.push_back(cloneGraph(x));
        }
        return n;

    }
};