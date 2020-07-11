/***
 * 6mins
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Minimum Depth of Binary Tree.
 * Memory Usage: 41.1 MB, less than 13.51% of Java online submissions for Minimum Depth of Binary Tree.
 */
public class Q111_MinimumDepthOfBinaryTree {
    public int minDepth(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int left = root.left == null ? Integer.MAX_VALUE : minDepth(root.left);
        int right = root.right == null ? Integer.MAX_VALUE : minDepth(root.right);
        int result = Math.min(left, right);
        return 1 + (result == Integer.MAX_VALUE ? 0 : result);
    }
}
