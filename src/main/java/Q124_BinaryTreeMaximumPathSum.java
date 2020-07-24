/***
 * 15mins Hard
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Binary Tree Maximum Path Sum.
 * Memory Usage: 41.1 MB, less than 82.78% of Java online submissions for Binary Tree Maximum Path Sum.
 */
public class Q124_BinaryTreeMaximumPathSum {
    int max = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        int result = rec(root);
        return max;
    }

    public int rec(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int left = rec(root.left);
        int right = rec(root.right);
        int r1 = root.val + (left < 0 ? 0 : left) + (right < 0 ? 0 : right);
        max = Math.max(max, r1);
        int r2 = Math.max(left, right);
        return root.val + (r2 < 0 ? 0 : r2);
    }
}
