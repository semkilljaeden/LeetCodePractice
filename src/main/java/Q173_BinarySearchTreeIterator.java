import java.util.ArrayDeque;
import java.util.Deque;

/***
 * 25mins medium
 * Runtime: 15 ms, faster than 93.81% of Java online submissions for Binary Search Tree Iterator.
 * Memory Usage: 44.2 MB, less than 87.13% of Java online submissions for Binary Search Tree Iterator.
 */
public class Q173_BinarySearchTreeIterator {
    Deque<TreeNode> stack = new ArrayDeque();
    public Q173_BinarySearchTreeIterator(TreeNode root) {
        TreeNode n = root;
        stack.addFirst(root);
        while(n != null && stack.size() > 0) {
            n = stack.peekFirst();
            if(n.right != null) {
                stack.addFirst(n.right);
            }
            if(n.left != null) {
                stack.addFirst(n.left);
            }
            n = n.left == null ? n.right : n.left;
        }
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode n = stack.removeFirst();

        return n.val;
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return stack.size() == 0;
    }
}
