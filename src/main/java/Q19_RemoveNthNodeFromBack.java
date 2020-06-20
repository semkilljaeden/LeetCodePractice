/***
 * Duration: 15mins
 *
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Nth Node From End of List.
 * Memory Usage: 37.6 MB, less than 64.11% of Java online submissions for Remove Nth Node From End of List.
 */
public class Q19_RemoveNthNodeFromBack {
    class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode prev = head;
        ListNode next = head;
        ListNode curr = head;
        ListNode probe = curr;
        int count = n;
        while(probe != null && count > 0) {
            probe = probe.next;
            count--;
        }
        if(count > 1) {
            return head;
        }
        else if(count == 1 && probe == null) {
            return head.next;
        }
        while(probe != null) {
            prev = curr;
            curr = curr.next;
            next = curr.next;
            probe = probe.next;
        }
        prev.next = next;
        return head;
    }
}


