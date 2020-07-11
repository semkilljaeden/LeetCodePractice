import java.util.ArrayDeque;
import java.util.Deque;

/***
 * 7mins easy
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Symmetric Tree.
 * Memory Usage: 37.7 MB, less than 72.30% of Java online submissions for Symmetric Tree.
 */

public class Q101_SymmetricTree {
    public boolean isSymmetric(TreeNode root) {
        if(root == null) {
            return true;
        }
        return rec(root.left, root.right);
    }

    public boolean rec(TreeNode left, TreeNode right) {
        if(left == null && right == null) {
            return true;
        }
        else if(left == null || right == null) {
            return false;
        }
        else if(left.val != right.val) {
            return false;
        }
        return rec(left.left, right.right) &&
                rec(left.right, right.left);
    }
}
