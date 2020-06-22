/***
 *Runtime: 0 ms, faster than 100.00% of Java online submissions for Merge Two Sorted Lists.
 * Memory Usage: 39.1 MB, less than 53.80% of Java online submissions for Merge Two Sorted Lists.
 */


public class Q21_MergeTwoSortedList {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode result;
        if(l1 == null || l2 == null) {
            return l1 != null ? l1 : l2;
        }

        if(l1.val < l2.val) {
            result = l1;
            l1 = l1.next;
        }
        else {
            result = l2;
            l2 = l2.next;
        }
        ListNode tmp;
        ListNode itr = result;
        while(l1 != null && l2 != null) {
            if(l1.val > l2.val) {
                itr.next = l2;
                tmp = l2.next;
                itr = itr.next;
                l2 = tmp;
            }
            else {
                itr.next = l1;
                tmp = l1.next;
                itr = itr.next;
                l1 = tmp;
            }
        }
        itr.next = l1 != null ? l1 : l2;
        return result;
    }

}
