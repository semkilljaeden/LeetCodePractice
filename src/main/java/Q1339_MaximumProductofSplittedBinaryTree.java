/***
 * 26mins, spend too much time for integer overflow....just use long
 * Runtime: 9 ms, faster than 80.82% of Java online submissions for Maximum Product of Splitted Binary Tree.
 * Memory Usage: 57.4 MB, less than 22.50% of Java online submissions for Maximum Product of Splitted Binary Tree.
 */
public class Q1339_MaximumProductofSplittedBinaryTree {
    public int maxProduct(TreeNode root) {
        sum(root);
        return (int) (max(root, 0) % 1000000007);
    }
    public long sum(TreeNode root) {
        if(root == null) {
            return 0;
        }
        root.val += sum(root.left) + sum(root.right);
        return root.val;
    }

    public long max(TreeNode root, long sum) {
        if(root == null) {
            return Integer.MIN_VALUE;
        }
        long left = root.left == null ? 0 : root.left.val;
        long right = root.right == null ? 0 : root.right.val;
        long max = Math.max(max(root.left, root.val - left + sum), max(root.right, root.val - right + sum));
        long max2 = Math.max(left * (root.val - left + sum), right * (root.val - right + sum));
        return Math.max(max, max2);
    }
}
