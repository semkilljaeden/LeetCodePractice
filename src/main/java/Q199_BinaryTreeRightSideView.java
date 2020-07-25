import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/***
 * 7mins medium, One shot AC
 * Runtime: 1 ms, faster than 84.50% of Java online submissions for Binary Tree Right Side View.
 * Memory Usage: 37.6 MB, less than 98.65% of Java online submissions for Binary Tree Right Side View.
 */
public class Q199_BinaryTreeRightSideView {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList();
        if(root == null) {
            return result;
        }
        Deque<TreeNode> queue = new ArrayDeque();
        int lc = 1;
        queue.addLast(root);
        while(queue.size() > 0) {
            int count = 0;
            TreeNode n = null;
            for(int i = 0; i < lc; i++) {
                n = queue.removeFirst();
                if(n.left != null) {
                    queue.addLast(n.left);
                    count++;
                }
                if(n.right != null) {
                    queue.addLast(n.right);
                    count++;
                }
            }
            if(n != null) {
                result.add(n.val);
            }
            lc = count;
        }
        return result;
    }
}
