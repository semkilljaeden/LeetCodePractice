import java.util.ArrayDeque;
import java.util.Deque;

/***
 * 24mins, easy, total failure. read the answer....
 * Runtime: 9 ms, faster than 26.33% of Java online submissions for Min Stack.
 * Memory Usage: 45.6 MB, less than 12.02% of Java online submissions for Min Stack.
 */
public class Q155_MinStack {
    Deque<Integer> min;
    Deque<Integer> stack;
    /** initialize your data structure here. */
    public Q155_MinStack() {
        min = new ArrayDeque();
        stack = new ArrayDeque();
    }

    public void push(int x) {
        if(min.size() == 0) {
            min.push(x);
        }
        else if(x < min.peek()) {
            min.push(x);
        }
        else {
            min.push(min.peek());
        }
        stack.push(x);
    }

    public void pop() {
        min.pop();
        stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return min.peek();
    }
}
