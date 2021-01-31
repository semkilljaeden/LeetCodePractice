#include<vector>
#include "TreeNode.cpp"
#include<stack>
using namespace std;
//9:33 9:40
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
Memory Usage: 8.5 MB, less than 83.36% of C++ online submissions for Binary Tree Preorder Traversal.
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> result;
        stack.push(root);
        while (stack.size() > 0)
        {
            auto node = stack.top();
            stack.pop();
            if (node == nullptr)
            {
                continue;
            }
            result.emplace_back(node->val);
            stack.push(node->right);
            stack.push(node->left);
        }
        return result;
    }
};

