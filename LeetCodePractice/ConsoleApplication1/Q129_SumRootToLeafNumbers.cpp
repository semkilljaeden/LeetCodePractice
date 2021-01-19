#include<vector>
#include "TreeNode.cpp"
using namespace std;
//9:20 to 9:28, too easy for a medium question

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum Root to Leaf Numbers.
Memory Usage: 12.3 MB, less than 99.69% of C++ online submissions for Sum Root to Leaf Numbers.

*/

class Solution {
public:
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        sumNumbers(root, 0);
        return sum;
    }

    void sumNumbers(TreeNode* root, int s)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            sum += s * 10 + root->val;
        }
        if (root->left != nullptr)
        {
            sumNumbers(root->left, s * 10 + root->val);
        }
        if (root->right != nullptr)
        {
            sumNumbers(root->right, s * 10 + root->val);
        }
    }
};