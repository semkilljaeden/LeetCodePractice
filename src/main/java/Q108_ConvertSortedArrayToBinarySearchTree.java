import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/***
 * 16mins, one typo makes a very silly bug
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Convert Sorted Array to Binary Search Tree.
 * Memory Usage: 42.4 MB, less than 6.54% of Java online submissions for Convert Sorted Array to Binary Search Tree.
 */

public class Q108_ConvertSortedArrayToBinarySearchTree {
    int[] nums;
    public TreeNode sortedArrayToBST(int[] nums) {
        this.nums = nums;
        return rec(0, nums.length - 1);
    }

    public TreeNode rec(int i, int j) {
        if(i > j) {
            return null;
        }
        if(i == j) {
            return new TreeNode(nums[i]);
        }
        int mid = i + (j - i) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = rec(i, mid - 1);
        root.right = rec(mid + 1, j);
        return root;
    }
}
