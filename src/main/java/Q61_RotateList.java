/***
 * 20min
 * Runtime: 2047 ms, faster than 5.01% of Java online submissions for Rotate List.
 * Memory Usage: 39.1 MB, less than 54.97% of Java online submissions for Rotate List.
 *
 * but this is for actual moving the node. otherwise can do calculation first then virtually move the node
 */
public class Q61_RotateList {
    public ListNode rotateRight(ListNode head, int k) {
        //next of slow is the new head
        //edge check
        if(head == null) {
            return null;
        }
        ListNode fast = head;
        ListNode slow = head;
        while(k > 0) {
            if(fast.next == null) {
                fast.next = head;
            }
            fast = fast.next;
            k--;
        }
        while(fast.next != null && !fast.next.equals(head)) {
            fast = fast.next;
            slow = slow.next;
        }
        if(fast.next == null) {
            fast.next = head;
        }
        ListNode result = slow.next;
        slow.next = null;
        return result;
    }
}
