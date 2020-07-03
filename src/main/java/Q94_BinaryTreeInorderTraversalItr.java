import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/***
 *Runtime: 1 ms, faster than 16.04% of Java online submissions for Binary Tree Inorder Traversal.
 * Memory Usage: 37.7 MB, less than 60.76% of Java online submissions for Binary Tree Inorder Traversal.
 */

public class Q94_BinaryTreeInorderTraversalItr {
    List<Integer> result;
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root == null) {
            return new ArrayList();
        }
        result = new ArrayList();
        LinkedList<Pair> stack = new LinkedList<Pair>();
        stack.add(new Pair(root.right));
        stack.add(new Pair(root, true));
        stack.add(new Pair(root.left));
        while(stack.size() > 0) {
            Pair t = stack.removeLast();
            if(t.tr == null) {
                continue;
            }
            if(t.visited) {
                result.add(t.tr.val);
            }
            else {
                t.visited = true;
                stack.add(new Pair(t.tr.right));
                stack.add(t);
                stack.add(new Pair(t.tr.left));
            }
        }
        return result;
    }

    public class Pair {
        TreeNode tr;
        boolean visited;
        public Pair(TreeNode t) {
            tr = t;
            visited = false;
        }
        public Pair(TreeNode t, boolean v) {
            tr = t;
            visited = true;
        }
    }
}
