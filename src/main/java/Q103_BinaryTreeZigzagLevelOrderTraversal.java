import java.util.*;

/***
 * 18mins
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Binary Tree Zigzag Level Order Traversal.
 * Memory Usage: 39.5 MB, less than 49.99% of Java online submissions for Binary Tree Zigzag Level Order Traversal.
 */

public class Q103_BinaryTreeZigzagLevelOrderTraversal {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        LinkedList<TreeNode> queue = new LinkedList();
        int level = 0;
        List<List<Integer>> result = new ArrayList();
        if(root == null) {
            return result;
        }
        queue.add(root);
        List<Integer> row = new ArrayList();
        while(queue.size() > 0) {
            int qs = queue.size();
            List<TreeNode> tmp = new ArrayList();
            for(int i = 0; i < qs; i++) {
                TreeNode t = queue.removeFirst();
                if(t != null) {
                    queue.add(t.left);
                    queue.add(t.right);
                    tmp.add(t);
                }
            }
            if(level % 2 == 0) {
                for(int i = 0; i < tmp.size(); i++) {
                    row.add(tmp.get(i).val);
                }
            }
            else {
                for(int i = tmp.size() - 1; i >= 0; i--) {
                    row.add(tmp.get(i).val);
                }
            }

            if(row.size() > 0) {
                result.add(row);
            }
            row = new ArrayList();
            level++;
        }
        return result;
    }
}
