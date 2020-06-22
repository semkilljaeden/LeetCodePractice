import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;

/***
 *
 * 16mins hard
 Runtime: 6 ms 38.7%
 Memory Usage: 41.6 MB

 O(logK * N)
 */

//Heap is slower than divide and conquer

public class Q23_MergeKSortedListV2 {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0 || lists == null) {
            return null;
        }
        PriorityQueue<ListNode> heap = new PriorityQueue<ListNode>(lists.length, Comparator.comparingInt(o -> o.val));
        for(int i = 0; i < lists.length; i++){
            if(lists[i] != null) {
                heap.add(lists[i]);
            }
        }
        if(heap.size() == 0) {
            return null;
        }
        ListNode itr = heap.poll();;
        ListNode root = itr;
        if(itr.next != null) {
            heap.offer(itr.next);
        }
        while(heap.size() > 0) {
            itr.next = heap.poll();
            itr = itr.next;
            if(itr.next != null) {
                heap.offer(itr.next);
            }

        }
        return root;
    }

}
