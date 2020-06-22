import java.util.LinkedList;
import java.util.List;

/***
 * Duration: 40min Medium
 *
 Runtime: 0 ms 100%
 Memory Usage: 39.6 MB  59.47%
 */

public class Q22_GenerateParenthV2 {
    List<String> result = new LinkedList<>();
    public List<String> generateParenthesis(int n) {
        generate(new StringBuilder(n * 2), 0 , 0, n);
        return result;
    }

    public void generate(StringBuilder sb, int open, int close, int count) {
        if(open == close && open == count) {
            result.add(sb.toString());
            return;
        }
        if(open < count) {
            generate(sb.append('('), open + 1, close, count);
            //DFS, once the child method return, just delete the last char to reuse the sb
            //Brilliant!
            sb.setLength(sb.length() - 1);

        }
        if(close < open) {
            generate(sb.append(')'), open, close + 1, count);
            sb.setLength(sb.length() - 1);
        }
    }
}