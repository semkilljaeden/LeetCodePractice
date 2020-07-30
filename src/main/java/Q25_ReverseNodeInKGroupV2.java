/***
 * 30mins
 *Runtime: 0 ms, faster than 100.00% of Java online submissions for Reverse Nodes in k-Group.
 * Memory Usage: 42.8 MB, less than 5.09% of Java online submissions for Reverse Nodes in k-Group.
 * */
public class Q25_ReverseNodeInKGroupV2 {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode psh = new ListNode();
        psh.next = head;
        ListNode prev = psh;
        ListNode curr = psh.next;
        ListNode end = curr;
        int i = 0;
        while(i < k && end != null) {
            end = end.next;
            i++;
        }
        if(i < k) {
            head = psh.next;
            return head;
        }
        //need bounday check
        while(true) {
            prev.next = rev(curr, end);
            curr.next = end;
            i = 0;
            prev = curr;
            curr = end;
            while(i < k && end != null) {
                end = end.next;
                i++;
            }
            if(i < k) {
                head = psh.next;
                return head;
            }
        }
    }


    public ListNode rev(ListNode curr, ListNode end) {
        if(curr.next == end) {
            return curr;
        }
        ListNode head = rev(curr.next, end);
        curr.next.next = curr;
        curr.next = null;
        return head;
    }
}
