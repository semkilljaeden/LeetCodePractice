import java.util.ArrayDeque;
import java.util.Deque;

/***
 * 12mins medium
 */
public class Q1249_MinimumRemovetoMakeValidParentheses {
    public String minRemoveToMakeValid(String s) {
        char[] c = s.toCharArray(); //just being lazy of using charAt, can be removed
        Deque<Integer> d = new ArrayDeque();
        boolean special = c[0] == ')';
        int i = special ? 1 : 0;
        for(; i < c.length; i++) {
            if(c[i] == '(') {
                d.addLast(i);
            }
            else if(c[i] == ')') {
                if(d.size() > 0 && d.peekLast() >= 0) {
                    d.removeLast();
                }
                else {
                    d.addLast(-i);  // the cute part
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        i = special ? 1 : 0;
        for(; i < c.length; i++) {
            if(d.size() > 0 && i == Math.abs(d.peekFirst())) {
                d.removeFirst();
            }
            else {
                sb.append(c[i]);
            }
        }
        return sb.toString();
    }
}
