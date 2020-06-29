/***
 * 20min
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Rotate List.
 * Memory Usage: 39.2 MB, less than 46.86% of Java online submissions for Rotate List.
 */
public class Q61_RotateListV2 {
    public ListNode rotateRight(ListNode head, int k) {
        //next of slow is the new head
        //edge check
        if(head == null) {
            return null;
        }
        ListNode fast = head;
        ListNode slow = head;
        int count = 0;
        while(slow.next != null) {
            slow = slow.next;
            count++;
        }
        slow = head;
        count++;
        k = k % count;
        while(k >= 0) {
            fast = fast.next;
            k--;
        }
        while(fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        fast.next = head;
        ListNode result = slow.next;
        slow.next = null;
        return result;
    }
}
