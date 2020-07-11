/***
 *1:10mins read the answer, thinking in the wrong direction. damn. I need to practice tree more often.
 * Runtime: 2 ms, faster than 80.66% of Java online submissions for Recover Binary Search Tree.
 * Memory Usage: 40.2 MB, less than 26.82% of Java online submissions for Recover Binary Search Tree.
 */

public class Q99_RecoverBinarySearchTree {
    TreeNode prev = null;
    TreeNode left = null;
    TreeNode right = null;



    public void recoverTree(TreeNode root) {
        rec(root);
        int tmp = left.val;
        left.val = right.val;
        right.val = tmp;
    }

    public void rec(TreeNode root) {
        if(root == null) {
            return;
        }
        rec(root.left);
        if(prev != null && prev.val > root.val) {
            if(left == null) {
                left = prev;
            }
            right = root;
        }
        prev = root;
        rec(root.right);

    }
}
