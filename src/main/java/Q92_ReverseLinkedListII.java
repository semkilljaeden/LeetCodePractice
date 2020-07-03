import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/***
 *first attempt 1 hour, somehow just could not get it right
 * second attempt 14mins, one shot AC.... what is happening.... why the first time i keep got it wrong.
 * I really need to relax after a long coding.
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Reverse Linked List II.
 * Memory Usage: 38.9 MB, less than 8.09% of Java online submissions for Reverse Linked List II.
 *
 * The solution on the recursive approach on revert linked list is amazing
 */
public class Q92_ReverseLinkedListII {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dh = new ListNode();//dummy head
        dh.next = head;
        n++; //make n a boundary
        ListNode itr = dh;
        for(int i = 0; i < m - 1; i++) { //itr to element before m
            itr = itr.next;
        }
        ListNode start = itr;
        ListNode rdh = new ListNode(); //reverse dummy head
        itr = rdh;
        //reverse
        ListNode f = start.next;
        ListNode t = f.next;
        start.next = null;
        f.next = itr;
        itr = f;
        rdh = itr;
        rdh.next = null;
        f = t;
        for(int i = m + 1; i < n; i++) {
            t = f.next;
            f.next = itr;
            itr = f;
            f = t;
        }
        start.next = itr;
        rdh.next = t;
        head = dh.next;
        dh.next = null;//clean up dummy head
        return head;
    }
}
