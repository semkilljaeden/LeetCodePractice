#include<vector>
#include "Node.cpp"
using namespace std;
//2:47 -> 3£º20 too slow!!!!!!!!!!!!!!! why am I degenerate so much!
/*
Runtime: 4 ms, faster than 99.97% of C++ online submissions for Populating Next Right Pointers in Each Node II.
Memory Usage: 17.7 MB, less than 84.59% of C++ online submissions for Populating Next Right Pointers in Each Node II.

*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL || root->right == NULL && root->left == NULL)
        {
            return root;
        }
        if (root->left != NULL)
        {
            root->left->next = root->right;
        }
        Node* c = NULL;
        if (root->right == NULL)
        {
            c = root->left;
        }
        else
        {
            c = root->right;
        }
        Node* p = root->next;
        while (p != NULL && p->left == NULL && p->right == NULL)
        {
            p = p->next;
        }
        if (p != NULL)
        {
            c->next = p->left != NULL ? p->left : p->right;
        }
        connect(root->right);
        connect(root->left);

        return root;
    }
};