/***
 *37mins, took some time to take care of integer boundary, have already anticipated, just did not expect the testcase
 * could really test it.
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Validate Binary Search Tree.
 * Memory Usage: 39.2 MB, less than 56.44% of Java online submissions for Validate Binary Search Tree.
 */

public class Q98_ValidateBinarySearchTree {
    public boolean isValidBST(TreeNode root) {
        Tuple r = recurse(root);
        return r.min > minv && r.max < maxv;
    }
    long minv = Integer.MIN_VALUE - 1L;
    long maxv = Integer.MAX_VALUE + 1L;
    public Tuple recurse(TreeNode root) {
        if(root == null) {
            return new Tuple(maxv, minv);
        }
        Tuple left = recurse(root.left);
        if(root.val <= left.max) {
            return new Tuple(minv, maxv);
        }
        Tuple right = recurse(root.right);
        if(root.val >= right.min) {
            return new Tuple(minv, maxv);
        }
        return new Tuple(left.min > root.val ? root.val : left.min, right.max < root.val ? root.val : right.max);

    }

    public class Tuple {
        long min;
        long max;

        public Tuple(long min, long max) {
            this.min = min;
            this.max = max;
        }
    }
}
