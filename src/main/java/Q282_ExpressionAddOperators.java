import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

/***
 * 1hr 20mins
 * Runtime: 189 ms, faster than 19.49% of Java online submissions for Expression Add Operators.
 * Memory Usage: 96.2 MB, less than 7.16% of Java online submissions for Expression Add Operators.
 */
public class Q282_ExpressionAddOperators {
    HashSet<String> result = new HashSet();
    String num;
    int t;
    char[] o = {'*', '+', '-'};
    public List<String> addOperators(String num, int target) {
        this.num = num;
        t = target;
        rec(0, 0, 1, 3, new StringBuilder());
        ArrayList<String> a = new ArrayList();
        for(String x : result) {
            a.add(x);
        }
        return a;
    }

    public void rec(int start, long arith, long multi, int action, StringBuilder sb) {
        if(start == num.length()) {
            if(arith + multi == t) {
                result.add(sb.toString());
            }
            return;
        }
        int length = sb.length();
        for(int i = start + 1; i <= num.length(); i++) {
            String tmp = num.substring(start, i);
            if(tmp.charAt(0) == '0' && tmp.length() > 1) {
                continue;
            }
            long x = Long.valueOf(tmp);
            switch(action) {
                case 0:
                    sb.append(o[0]);
                    sb.append(x);
                    rec(i, arith, multi * x, 0, sb);
                    rec(i, arith + multi * x, 0, 1, sb);
                    rec(i, arith + multi * x, 0, 2, sb);
                    sb.setLength(length);
                    break;
                case 1:
                    sb.append(o[1]);
                    sb.append(x);
                    rec(i, arith, x, 0, sb);
                    rec(i, arith + x, 0, 1, sb);
                    rec(i, arith + x, 0, 2, sb);
                    sb.setLength(length);
                    break;
                case 2:
                    sb.append(o[2]);
                    sb.append(x);
                    rec(i, arith, -x, 0, sb);
                    rec(i, arith - x, 0, 1, sb);
                    rec(i, arith - x, 0, 2, sb);
                    sb.setLength(length);
                    break;
                case 3:
                    sb.append(x);
                    rec(i, 0, x, 0, sb);
                    rec(i, x, 0, 1, sb);
                    rec(i, x, 0, 2, sb);
                    sb.setLength(length);
                    break;


            }

        }
    }
}
