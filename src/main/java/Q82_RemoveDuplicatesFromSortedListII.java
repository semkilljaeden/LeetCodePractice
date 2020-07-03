/**
 * 1:30hr, medium, go for a wrong direction, but one shot AC
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Duplicates from Sorted List II.
 * Memory Usage: 38.9 MB, less than 86.00% of Java online submissions for Remove Duplicates from Sorted List II.
 */
public class Q82_RemoveDuplicatesFromSortedListII {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null) {
            return null;
        }
        ListNode f = head;
        ListNode newHead = new ListNode();
        ListNode itr = newHead;
        ListNode prev = newHead;
        itr.next = head;
        itr = itr.next;
        int p = head.val;
        f = f.next;
        boolean isDeleted = false;
        while(f != null) {
            if(f.val == p) {
                if(!isDeleted) {
                    prev.next = null;
                    itr = prev;
                    isDeleted = true;
                }
            }
            else {
                itr.next = f;
                prev = itr;
                itr = itr.next;
                isDeleted = false;
                p = f.val;
            }
            f = f.next;
        }
        return newHead.next;
    }
}
