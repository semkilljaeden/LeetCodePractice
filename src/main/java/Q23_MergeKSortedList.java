import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;

import static java.util.Arrays.copyOf;

/***
 *
 * 16mins hard
 Runtime: 259 ms, faster than 7.03% of Java online submissions for Merge k Sorted Lists.
 Memory Usage: 41.2 MB, less than 59.00% of Java online submissions for Merge k Sorted Lists.

 O(k * n)
 */

public class Q23_MergeKSortedList {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0 || lists == null) {
            return null;
        }
        ListNode result;
        ListNode root;
        int count = 0;
        int index = -1;
        int value = Integer.MAX_VALUE;
        for (int i = 0; i < lists.length; i++) {
            if (lists[i] == null) {
                count++;
                continue;
            }
            if (lists[i].val < value) {
                index = i;
                value = lists[i].val;
            }
        }
        if (count == lists.length) {
            return null;
        }
        result = lists[index];
        lists[index] = lists[index].next;
        if (lists[index] == null) {
            count++;
        }
        root = result;
        while (count < lists.length) {
            index = -1;
            value = Integer.MAX_VALUE;
            for (int i = 0; i < lists.length; i++) {
                if (lists[i] == null) {
                    continue;
                }
                if (lists[i].val < value) {
                    index = i;
                    value = lists[i].val;
                }
            }
            result.next = lists[index];
            result = result.next;
            lists[index] = lists[index].next;
            if (lists[index] == null) {
                count++;
            }

        }
        return root;
    }
}
