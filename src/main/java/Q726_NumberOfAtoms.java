import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Map;
import java.util.TreeMap;

/***
 * 59mins
 * Runtime: 3 ms, faster than 92.41% of Java online submissions for Number of Atoms.
 * Memory Usage: 37.9 MB, less than 41.60% of Java online submissions for Number of Atoms.
 */
public class Q726_NumberOfAtoms {
    TreeMap<String, Integer> map = new TreeMap();
    char[] c;
    public String countOfAtoms(String formula) {
        if(formula.length() == 0) {
            return "";
        }
        c = formula.toCharArray();
        rec(0, c.length, 1);
        StringBuilder sb = new StringBuilder();
        for(Map.Entry<String, Integer> e : map.entrySet()) {
            sb.append(e.getKey());
            if(e.getValue() > 1) {
                sb.append(e.getValue());
            }
        }
        return sb.toString();
    }

    public void rec(int start, int end, int m) {
        if(start >= end) {
            return;
        }
        int i = start;
        //left load
        StringBuilder sb = new StringBuilder();
        StringBuilder count = new StringBuilder();
        while(i < end && c[i] != '(') {
            if(c[i] <= 'z' && c[i] >= 'a') {
                sb.append(c[i]);
            }
            else if(c[i] <= 'Z' && c[i] >= 'A') {
                if(sb.length() > 0) {
                    String element = sb.toString();
                    int cc = count.length() > 0 ? Integer.valueOf(count.toString()) : 1;
                    map.put(element, map.getOrDefault(element, 0) + cc * m);
                    sb.setLength(0);
                    count.setLength(0);
                }
                sb.append(c[i]);
            }
            else if(c[i] >= '0' && c[i] <= '9'){
                count.append(c[i]);
            }
            i++;
        }
        if(sb.length() > 0) {
            String element = sb.toString();
            int c = count.length() > 0 ? Integer.valueOf(count.toString()) : 1;
            map.put(element, map.getOrDefault(element, 0) + c * m);
        }
        count.setLength(0);
        if(i < end && c[i] == '(') {
            Deque<Character> stack = new ArrayDeque();
            stack.addLast(c[i++]);
            int j = i;
            while(j < end) {
                if(c[j] == '(') {
                    stack.addLast('(');
                }
                else if(c[j] == ')') {
                    stack.removeLast();
                    if(stack.size() == 0) {
                        break;
                    }
                }
                j++;
            }
            int k = j + 1;
            while(k < end && c[k] >= '0' && c[k] <= '9') {
                count.append(c[k++]);
            }
            rec(i, j, Integer.valueOf(count.toString()) * m);
            i = k;
        }
        rec(i, end, m);
    }
}
