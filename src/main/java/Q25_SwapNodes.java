/***
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Swap Nodes in Pairs. Medium
 * Memory Usage: 37.1 MB, less than 54.57% of Java online submissions for Swap Nodes in Pairs.
 */
public class Q25_SwapNodes {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) {
            return head;
        }
        ListNode curr = head;
        ListNode prev;
        ListNode next = curr.next;
        curr.next = next.next;
        next.next = curr;
        prev = next;
        ListNode root = prev;
        while(curr.next != null && curr.next.next != null) {
            prev = curr;
            curr = curr.next;
            next = curr.next;
            curr.next = next.next;
            next.next = curr;
            prev.next = next;
        }
        return root;
    }
    public class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
}
