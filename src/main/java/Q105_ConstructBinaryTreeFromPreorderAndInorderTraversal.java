import java.util.Arrays;

/***
 * 1:30hr. damn
 * too slow
 * Runtime: 24 ms, faster than 5.14% of Java online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
 * Memory Usage: 75.9 MB, less than 5.06% of Java online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
 */

public class Q105_ConstructBinaryTreeFromPreorderAndInorderTraversal {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length == 0 || inorder.length == 0) {
            return null;
        }
        return rec(preorder, inorder);
    }

    public TreeNode rec(int[] preorder, int[] inorder) {
        if(preorder == null || preorder.length == 0) {
            return null;
        }
        if(preorder.length == 1) {
            return new TreeNode(preorder[0]);
        }
        int i = 0;
        for(i = 0; i < inorder.length; i++) {
            if(inorder[i] == preorder[0]) {
                break;
            }
        }
        TreeNode root = new TreeNode(preorder[0]);
        root.left = rec(copy(preorder, 1, i + 1),
                copy(inorder, 0, i));
        root.right = rec(copy(preorder, i + 1, preorder.length),
                copy(inorder, i + 1, inorder.length));
        return root;
    }

    public int[] copy(int[] origin, int s, int e) {
        if(s >= origin.length) {
            return null;
        }
        return Arrays.copyOfRange(origin, s, e);
    }
}
