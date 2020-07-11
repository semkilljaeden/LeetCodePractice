import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

/***
 * 12mins. best solution, perfect one shot AC
 * Runtime: 1 ms, faster than 88.82% of Java online submissions for Binary Tree Level Order Traversal II.
 * Memory Usage: 40.1 MB, less than 22.83% of Java online submissions for Binary Tree Level Order Traversal II.
 */

public class Q107_BinaryTreeLevelOrderTraversalII {
    LinkedList<List<Integer>> result = new LinkedList();
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        rec(root, 0);
        return result;
    }

    public void rec(TreeNode root, int level) {
        if(root == null) {
            return;
        }
        if(result.size() == level) {
            result.addFirst(new ArrayList());
        }
        rec(root.left, level + 1);
        rec(root.right, level + 1);
        result.get(result.size() - level - 1).add(root.val);
    }
}
