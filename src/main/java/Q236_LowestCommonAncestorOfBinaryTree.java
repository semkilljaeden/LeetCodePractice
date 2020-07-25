/***
 * 5mins medium one shot AC
 * Runtime: 4 ms, faster than 100.00% of Java online submissions for Lowest Common Ancestor of a Binary Tree.
 * Memory Usage: 42.1 MB, less than 15.01% of Java online submissions for Lowest Common Ancestor of a Binary Tree.
 */
public class Q236_LowestCommonAncestorOfBinaryTree {
    TreeNode result = null;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        rec(root, p, q);
        return result;
    }

    public boolean rec(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || result != null) {
            return false;
        }
        boolean l = rec(root.left, p, q);
        boolean r = rec(root.right, p, q);
        boolean c = root.val == p.val || root.val == q.val;
        if(result == null && (l && r || (l || r) && c)) {
            result = root;
        }
        return l || r || c;
    }

}
