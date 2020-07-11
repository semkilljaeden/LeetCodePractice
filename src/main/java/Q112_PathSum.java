/***
 * 5mins
 * untime: 0 ms, faster than 100.00% of Java online submissions for Path Sum.
 * Memory Usage: 40.7 MB, less than 16.92% of Java online submissions for Path Sum.
 */
public class Q112_PathSum {
    boolean result = false;
    int sum;
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null) {
            return false;
        }
        this.sum = sum;
        rec(root, 0);
        return result;
    }

    public void rec(TreeNode root, int sum) {
        if(root == null) {
            return;
        }
        if(root.left == null && root.right == null) {
            if(this.sum == sum + root.val) {
                result = true;
            }
            return;
        }
        rec(root.left, sum + root.val);
        rec(root.right, sum + root.val);
    }
}
