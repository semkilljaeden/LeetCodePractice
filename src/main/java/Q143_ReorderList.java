/***
 * 45mins, debugging silly bug
 * Runtime: 1 ms, faster than 99.94% of Java online submissions for Reorder List.
 * Memory Usage: 44.3 MB, less than 5.04% of Java online submissions for Reorder List.
 */
public class Q143_ReorderList {
    ListNode curr;
    ListNode h;
    int count = 0;
    public void reorderList(ListNode head) {
        curr = new ListNode();
        ListNode tmp = curr;
        h = head;
        rec(head);
        tmp.next = null;
    }

    public void rec(ListNode head) {
        if(head == null) {
            return;
        }
        count++;
        rec(head.next);
        if(count > 1) {
            curr.next = h;
            h = h.next;
            curr = curr.next;
            curr.next = head;
            curr = curr.next;
            curr.next = null;
            count -= 2;
        }
        else if(count == 1) {
            curr.next = head;
            head.next = null;
            count--;
        }
    }
}
