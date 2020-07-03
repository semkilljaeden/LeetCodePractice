import java.util.Arrays;
import java.util.LinkedList;

/***
 * 40mins O(n)
 */
public class Q32_LongtestValidParentheseGreedy {
    public int longestValidParentheses(String s) {
        LinkedList<Integer> stack = new LinkedList<Integer>();
        int i = 0;
        int result = 0;
        int newStackPos = 0;
        while (i < s.length()) {
            char c = s.charAt(i++);
            //failed case
            if(stack.size() == 0 && c == ')') {
                newStackPos = i;
                continue;
            }
            else if(stack.size() == 0 && c == '(') {
                stack.addLast(i);
            }
            else if(c == '(') {
                stack.addLast(i);
            }
            else if(c == ')') {
                stack.removeLast();
                result = Math.max(result, i - (stack.size() == 0 ? newStackPos : stack.getLast()));
            }

        }
        return result;
    }
}
