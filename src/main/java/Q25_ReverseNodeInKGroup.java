import java.util.LinkedList;

/***
 * 45mins Hard
 *
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Reverse Nodes in k-Group.
 * Memory Usage: 39 MB, less than 99.91% of Java online submissions for Reverse Nodes in k-Group.
 */

//Remember JAVA object comparison use equals!!!


public class Q25_ReverseNodeInKGroup {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode tail = head;
        if(tail == null) {
            return null;
        }
        if(k == 1) {
            return head;
        }
        for(int i = 0; i < k - 1; i++) {
            tail = tail.next;
            if(tail == null) {
                return head;
            }
        }
        ListNode root = reverse(head, tail);
        tail = head;
        ListNode prev;
        while(true) {
            prev = tail;
            head = tail.next;
            tail = head;
            if(tail == null) {
                return root;
            }
            for(int i = 0; i < k - 1; i++) {
                tail = tail.next;
                if(tail == null) {
                    return root;
                }
            }
            prev.next = reverse(head, tail);
            tail = head;
        }
    }

    public ListNode reverse(ListNode head, ListNode tail) {
        ListNode next = null;
        while(!head.equals(tail)) {
            next = head.next;
            head.next = tail.next;
            tail.next = head;
            head = next;
        }
        return next;
    }

    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
}
