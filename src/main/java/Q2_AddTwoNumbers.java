/***
 * Runtime: 2 ms  59.06%
 * Memory Usage: 39.7 MB
 */

public class Q2_AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int temp = l1.val + l2.val;
        int reminder = temp >= 10 ? 1 : 0;
        int value = temp % 10;
        ListNode result = new ListNode(value);
        ListNode head = result;
        l1 = l1.next;
        l2 = l2.next;
        while(l1 != null || l2 != null || reminder > 0) {
            int l1V;
            int l2V;
            if(l1 == null) {
                l1V = 0;

            }
            else {
                l1V = l1.val;
                l1 = l1.next;
            }
            if(l2 == null) {
                l2V = 0;
            }
            else {
                l2V = l2.val;
                l2 = l2.next;
            }
            temp = l1V + l2V + reminder;
            reminder = temp >= 10 ? 1 : 0;
            value = temp % 10;
            result.next = new ListNode(value);
            result = result.next;
        }
        return head;
    }
}


