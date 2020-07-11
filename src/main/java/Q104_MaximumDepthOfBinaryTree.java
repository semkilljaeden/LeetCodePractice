import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/***
 * 1mins easiest question of my life
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Maximum Depth of Binary Tree.
 * Memory Usage: 40.6 MB, less than 9.20% of Java online submissions for Maximum Depth of Binary Tree.
 */

public class Q104_MaximumDepthOfBinaryTree {
    public int maxDepth(TreeNode root) {
        if(root == null) {
            return 0;
        }
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}
