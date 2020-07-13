/***
 * 4mins. fantastic recursive solution
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Reverse Linked List.
 * Memory Usage: 39.4 MB, less than 51.74% of Java online submissions for Reverse Linked List.
 */
public class Q206_ReverseLinkedList {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) {
            return head;
        }
        ListNode h = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return h;
    }
}
