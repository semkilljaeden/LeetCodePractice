import java.util.Arrays;
import java.util.HashMap;

/***
 * 30mins
 * why so slow??
 *
 * Runtime: 8 ms, faster than 11.54% of Java online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
 * Memory Usage: 42.3 MB, less than 9.64% of Java online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
 *
 * use index hashmap to speed up
 * Runtime: 1 ms, faster than 96.81% of Java online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
 * Memory Usage: 39.9 MB, less than 41.62% of Java online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
 */

public class Q106_ConstructBinaryTreeFromInorderAndPostorderTraversal {
    int[] inorder;
    int[] postorder;
    HashMap<Integer, Integer> indexMap = new HashMap();
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(inorder.length == 0 || postorder.length == 0) {
            return null;
        }
        this.inorder = inorder;
        this.postorder = postorder;
        for(int i = 0; i < inorder.length; i++) {
            indexMap.put(inorder[i], i);
        }
        return rec(0, inorder.length, 0, postorder.length);
    }

    public TreeNode rec(int si, int ei, int sp, int ep) {
        if(ei - si == 1) {
            return new TreeNode(postorder[ep - 1]);
        }
        if(si >= ei) {
            return null;
        }
        int i = indexMap.get(postorder[ep - 1]);
        TreeNode root = new TreeNode(postorder[ep - 1]);
        root.right = rec(i + 1, ei, i - si + sp, ep - 1);
        root.left = rec(si, i, sp, i - si + sp);
        return root;
    }
}
