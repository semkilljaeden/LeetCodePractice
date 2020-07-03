import java.util.ArrayList;
import java.util.List;

/***
 *3mins, recursive approach is too easy
 *
 *Runtime: 0 ms, faster than 100.00% of Java online submissions for Binary Tree Inorder Traversal.
 * Memory Usage: 37.8 MB, less than 48.75% of Java online submissions for Binary Tree Inorder Traversal.
 */

public class Q94_BinaryTreeInorderTraversal {
    List<Integer> result;
    public List<Integer> inorderTraversal(TreeNode root) {
        result = new ArrayList();
        recurse(root);
        return result;
    }

    public void recurse(TreeNode root) {
        if(root == null) {
            return;
        }
        recurse(root.left);
        result.add(root.val);
        recurse(root.right);
    }


}
