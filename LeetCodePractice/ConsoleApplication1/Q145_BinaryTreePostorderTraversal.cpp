#include<vector>
#include "TreeNode.cpp"
#include<stack>
using namespace std;
//9:41 9:49

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
Memory Usage: 8.5 MB, less than 83.36% of C++ online submissions for Binary Tree Preorder Traversal.
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> result;
        s1.push(root);
        while (s1.size() > 0)
        {
            auto node = s1.top();
            s1.pop();
            if (node == nullptr)
            {
                continue;
            }
            s2.push(node);
            s1.push(node->left);
            s1.push(node->right);
        }
        while (s2.size() > 0)
        {
            auto node = s2.top();
            s2.pop();
            result.push_back(node->val);
        }
        return result;
    }
};

