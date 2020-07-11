import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/***
 * 12mins medium, need to think of a recursive solution
 * Runtime: 1 ms, faster than 63.63% of Java online submissions for Binary Tree Level Order Traversal.
 * Memory Usage: 39.9 MB, less than 37.12% of Java online submissions for Binary Tree Level Order Traversal.
 */

public class Q102_BinaryTreeLevelOrderTraversal {
    public List<List<Integer>> levelOrder(TreeNode root) {
        Deque<Tuple> queue = new ArrayDeque();
        List<List<Integer>> result = new ArrayList();
        List<Integer> row = new ArrayList();
        if(root == null) {
            return result;
        }
        queue.add(new Tuple(root, 0));
        int prevLevel = 0;
        while(queue.size() > 0) {
            Tuple t = queue.removeFirst();
            if(t.level > prevLevel) {
                result.add(row);
                row = new ArrayList();
                prevLevel = t.level;
            }
            row.add(t.node.val);
            if(t.node.left != null) {
                queue.add(new Tuple(t.node.left, t.level + 1));
            }
            if(t.node.right != null) {
                queue.add(new Tuple(t.node.right, t.level + 1));
            }

        }
        result.add(row);
        return result;
    }

    public class Tuple {
        TreeNode node;
        int level;
        public Tuple(TreeNode t, int level) {
            this.node = t;
            this.level = level;
        }

    }
}
