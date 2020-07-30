/***
 * 30mins
 *Runtime: 0 ms, faster than 100.00% of Java online submissions for Reverse Nodes in k-Group.
 * Memory Usage: 42.8 MB, less than 5.09% of Java online submissions for Reverse Nodes in k-Group.
 * */
public class Q25_ReverseNodeInKGroupV3 {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null) {
            return null;
        }
        ListNode curr = head;
        int i = 0;
        for(i = 0; i < k - 1; i++) {
            curr = curr.next;
            if(curr == null) {
                break;
            }
        }
        if(i == k - 1 && curr != null) {
            ListNode end = curr.next;
            ListNode h = rev(head, curr);
            head.next = reverseKGroup(end, k);
            return h;
        }
        else {
            return head;
        }
    }


    public ListNode rev(ListNode head, ListNode curr) {
        if(head == curr) {
            return curr;
        }
        ListNode h = rev(head.next, curr);
        head.next.next = head;
        head.next = null;
        return h;
    }
}
