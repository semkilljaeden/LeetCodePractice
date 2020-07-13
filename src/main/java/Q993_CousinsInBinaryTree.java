import java.util.ArrayDeque;
import java.util.Deque;

/***
 * 17mins harder easy
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Cousins in Binary Tree.
 * Memory Usage: 37.4 MB, less than 52.53% of Java online submissions for Cousins in Binary Tree.
 */
public class Q993_CousinsInBinaryTree {
    TreeNode xp;
    TreeNode yp;
    int xl = -1;
    int yl = -1;
    int x;
    int y;
    public boolean isCousins(TreeNode root, int x, int y) {
        this.x = x;
        this.y = y;
        return dfs(root, root, 1);
    }

    public boolean dfs(TreeNode root, TreeNode parent, int level) {
        if(root == null) {
            return false;
        }
        if(root.val == x) {
            if(yp != null) {
                xp = parent;
                return level == yl && xp.val != yp.val;
            }
            else {
                xp = parent;
                xl = level;
            }
        }
        else if(root.val == y) {
            if(xp != null) {
                yp = parent;
                return level == xl && xp.val != yp.val;
            }
            else {
                yp = parent;
                yl = level;
            }
        }
        return dfs(root.left, root, level + 1) || dfs(root.right, root, level + 1);
    }
}
