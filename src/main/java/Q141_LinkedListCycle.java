/***
 * 8mins, best solution
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Linked List Cycle.
 * Memory Usage: 39.5 MB, less than 70.97% of Java online submissions for Linked List Cycle.
 */
public class Q141_LinkedListCycle {
    public boolean hasCycle(ListNode head) {
        ListNode fast = head; //double speed
        ListNode slow = head; //normal speed
        while(fast != null && fast.next != null && slow != null) {
            fast = fast.next.next;
            slow = slow.next;
            if(fast != null && fast.equals(slow)) {
                return true;
            }
        }
        return false;
    }
}
