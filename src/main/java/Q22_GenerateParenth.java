import java.util.LinkedList;
import java.util.List;

/***
 * Duration: 40min Medium
 *
 * Runtime: 3 ms, faster than 24.96% of Java online submissions for Generate Parentheses.
 * Memory Usage: 41.2 MB, less than 6.80% of Java online submissions for Generate Parentheses.
 */

public class Q22_GenerateParenth {
    List<String> result = new LinkedList<>();
    public List<String> generateParenthesis(int n) {
        generate(new StringBuilder(), 0 , 0, n);
        return result;
    }

    public void generate(StringBuilder sb, int open, int close, int count) {
        if(open == close && open == count) {
            result.add(sb.toString());
            return;
        }
        if(open < count) {
            generate(new StringBuilder(sb).append('('), open + 1, close, count);

        }
        if(close < open) {
            generate(new StringBuilder(sb).append(')'), open, close + 1, count);
        }
    }
}
