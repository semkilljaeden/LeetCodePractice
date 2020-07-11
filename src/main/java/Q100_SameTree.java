import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;

/***
 *9mins easy question, one shot AC
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Same Tree.
 * Memory Usage: 39.1 MB, less than 5.09% of Java online submissions for Same Tree.
 */

public class Q100_SameTree {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        Deque<TreeNode> stackp = new ArrayDeque();
        Deque<TreeNode> stackq = new ArrayDeque();
        stackp.add(p);
        stackq.add(q);
        while(stackp.size() > 0 && stackq.size() > 0) {
            TreeNode tp = stackp.pop();
            TreeNode tq = stackq.removeLast();
            if(tq == null && tp == null) {
                continue;
            }
            else if(tq == null || tp == null) {
                return false;
            }
            else if(tq.val != tp.val) {
                return false;
            }
            stackq.add(tq.left);
            stackq.add(tq.right);
            stackp.add(tp.left);
            stackp.add(tp.right);
        }
        return stackp.size() == 0 && stackq.size() == 0;
    }
//Recursion version
    public boolean isSameTree2(TreeNode p, TreeNode q) {
        if (p == null || q == null) return p == q;
        if (p.val != q.val) return false;
        return isSameTree2(p.left, q.left) && isSameTree2(p.right , q.right);
    }
}
