/***
 * 25mins, read the answer, implemented approach 3. this approach is amazing.
 * I have thought of other implementations, not worthy to do, too obvious
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Convert Sorted List to Binary Search Tree.
 * Memory Usage: 40.6 MB, less than 66.07% of Java online submissions for Convert Sorted List to Binary Search Tree.
 *
 * Inorder traversal simulation!!!!!!
 */

public class Q109_ConvertSortedListToBinarySearchTree {
    ListNode head;
    public TreeNode sortedListToBST(ListNode head) {
        int end = 0;
        ListNode itr = head;
        while(itr != null) {
            end++;
            itr = itr.next;
        }
        this.head = head;
        return rec(0, end);
    }

    public TreeNode rec(int start, int end) {
        if(head == null) {
            return null;
        }
        if(start > end) {
            return null;
        }
        if(start == end) {
            TreeNode root = new TreeNode(head.val);
            head = head.next;
            return root;
        }
        int mid = start + (end - start) / 2;
        TreeNode left = rec(start, mid - 1);
        TreeNode root = new TreeNode(head.val);
        head = head.next;
        TreeNode right = rec(mid + 1, end);
        root.left = left;
        root.right = right;
        return root;
    }
}
