import java.util.HashMap;

/***
 * 1:30hr, spend too much time on debugging double linked list
 */
public class Q146_LRUCache {
    HashMap<Integer, Node> cache;
    int cap;
    List list = new List();
    public Q146_LRUCache(int capacity) {
        cache = new HashMap(capacity);
        cap = capacity;
    }

    public int get(int key) {
        if(!cache.containsKey(key)) {
            return -1;
        }
        Node n = cache.get(key);
        list.remove(n);
        list.add(n);
        return n.value;
    }

    public void put(int key, int value) {
        if(cache.containsKey(key)) {
            list.remove(cache.remove(key));
        }
        if(list.size == cap) {
            Node n = list.removeFirst();
            cache.remove(n.key);
        }
        Node n = new Node(key, value);
        cache.put(key, n);
        list.add(n);
    }

    private class Node {
        Node prev;
        Node next;
        int value;
        int key;
        public Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    private class List {
        Node first = null;
        Node last = null;
        int size = 0;
        public void add(Node n) {
            if(size == 0) {
                first = n;
                last = n;
                n.prev = null;
                n.next = null;
            }
            else {
                last.next = n;
                n.prev = last;
                last = n;
                last.next = null;
            }
            size++;
        }

        public void remove(Node n) {
            if(size == 0) {
                return;
            }
            if(size == 1) {
                first = null;
                last = null;
            }
            else if(n.equals(first)) {
                removeFirst();
                return;
            }
            else if(n.equals(last)) {
                last = last.prev;
                last.next = null;
            }
            else {
                n.prev.next = n.next;
                n.next.prev = n.prev;
            }
            n.prev = null;
            n.next = null;
            size--;
        }

        public Node removeFirst() {
            if(size == 0) {
                return null;
            }
            Node r = first;
            if(size == 1) {
                first = null;
                last = null;
                r.prev = null;
                r.next = null;
            }
            else {
                first = first.next;
                r.prev = null;
                r.next = null;
            }
            size--;
            return r;
        }
    }
}
