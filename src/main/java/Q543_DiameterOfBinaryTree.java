/***
 * 9mins
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Diameter of Binary Tree.
 * Memory Usage: 39.5 MB, less than 44.25% of Java online submissions for Diameter of Binary Tree.
 */
public class Q543_DiameterOfBinaryTree {
    int result = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        rec(root);
        return result;
    }

    public int rec(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int left = rec(root.left);
        int right = rec(root.right);
        result = Math.max(result, left + right);
        return Math.max(left, right) + 1;
    }
}
