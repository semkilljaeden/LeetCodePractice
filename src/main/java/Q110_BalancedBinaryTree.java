/***
 * 3mins one shot AC
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Balanced Binary Tree.
 * Memory Usage: 39.4 MB, less than 78.15% of Java online submissions for Balanced Binary Tree.
 */
public class Q110_BalancedBinaryTree {
    boolean isB = true;
    public boolean isBalanced(TreeNode root) {
        rec(root);
        return isB;
    }

    public int rec(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int left = rec(root.left);
        int right = rec(root.right);
        if(Math.abs(left - right) > 1) {
            isB = false;
        }
        return 1 + Math.max(left, right);
    }
}
