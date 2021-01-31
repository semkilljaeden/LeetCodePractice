#include<vector>
#include "Node.cpp"

//2:00 to 2:37
//read the solution, the solution is brilliant, sad i did not come up with my own. the code is quite ez
/*
Runtime: 12 ms, faster than 98.88 % of C++ online submissions for Populating Next Right Pointers in Each Node.
Memory Usage : 17.3 MB, less than 57.13 % of C++ online submissions for Populating Next Right Pointers in Each Node.
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL || root->left == NULL || root->right == NULL)
        {
            return root;
        }
        root->left->next = root->right;
        if (root->next != NULL)
        {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};