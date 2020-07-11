import java.util.ArrayList;
import java.util.List;

/***
 * 10mins
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Flatten Binary Tree to Linked List.
 * Memory Usage: 39.4 MB, less than 37.12% of Java online submissions for Flatten Binary Tree to Linked List.
 */
public class Q114_FlattenBinaryTreeToLinkedList {
    TreeNode nr = new TreeNode();
    TreeNode itr;
    public void flatten(TreeNode root) {
        itr = nr;
        rec(root);
        nr.right = null;
        nr.left = null;
    }

    public void rec(TreeNode root) {
        if(root == null) {
            return;
        }
        itr.right = root;
        itr.left = null;
        itr = itr.right;
        TreeNode left = root.left;
        TreeNode right = root.right;
        itr.left = null;
        itr.right = null;
        rec(left);
        rec(right);
    }
    //original wrong implementation
    /***
     *     public void rec(TreeNode root) {
     *         if(root == null) {
     *             return;
     *         }
     *         itr.right = root;
     *         itr.left = null;
     *         itr = itr.right;
     *         System.out.println(itr.val);
     *         rec(root.left);
     *         rec(root.right); // previous one has modified root.right when called back, need to store left and right
     *     }
     */
}
