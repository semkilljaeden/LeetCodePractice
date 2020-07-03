/**
 * 8mins medium. Perfect one shot AC. even no "run code" errors. First time since Q1! nice
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Partition List.
 * Memory Usage: 39.1 MB, less than 53.30% of Java online submissions for Partition List.
 */
public class Q86_PartitionList {
    public ListNode partition(ListNode head, int x) {
        if(head == null) {
            return null;
        }
        ListNode left = new ListNode();
        ListNode leftRoot = left;
        ListNode right = new ListNode();
        ListNode rightRoot = right;
        while(head != null) {
            ListNode tmp = head.next;
            if(head.val < x) {
                left.next = head;
                left = left.next;
                left.next = null;
            }
            else {
                right.next = head;
                right = right.next;
                right.next = null;
            }
            head = tmp;
        }
        left.next = rightRoot.next;
        rightRoot.next = null;
        ListNode result = leftRoot.next;
        leftRoot.next = null;
        return result;
    }
}
