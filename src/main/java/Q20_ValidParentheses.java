import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/***
 * 10mins
 *
 * Runtime: 1 ms, faster than 98.78% of Java online submissions for Valid Parentheses.
 * Memory Usage: 37.2 MB, less than 85.06% of Java online submissions for Valid Parentheses.
 */
public class Q20_ValidParentheses {
    public boolean isValid(String s) {
        if(s == "" || s == null) {
            return true;
        }
        Stack<Character> stack = new Stack<>();
        Map<Character, Character> map = new HashMap<>();
        map.put('(', ')');
        map.put('{', '}');
        map.put('[', ']');
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '{' || s.charAt(i) == '(' || s.charAt(i) == '[') {
                stack.push(s.charAt(i));
            }
            else {
                if(stack.size() == 0 || map.get(stack.pop()) != s.charAt(i)) {
                    return false;
                }
            }
        }
        return stack.size() == 0;
    }
}
