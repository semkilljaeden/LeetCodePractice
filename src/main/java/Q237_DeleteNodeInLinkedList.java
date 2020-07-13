/***
 * 6mins
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Delete Node in a Linked List.
 * Memory Usage: 38.8 MB, less than 62.46% of Java online submissions for Delete Node in a Linked List.
 */
public class Q237_DeleteNodeInLinkedList {
    public void deleteNode(ListNode node) {
        if(node.next == null) {
            return;
        }
        while(node.next.next != null) {
            node.val = node.next.val;
            node = node.next;
        }
        node.val = node.next.val;
        node.next = null;
    }
}
