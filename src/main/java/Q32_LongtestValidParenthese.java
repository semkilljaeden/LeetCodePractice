import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

/***
 * 1H10Mins Hard
 *
 * Runtime: 3 ms  35.91%
 * Memory Usage: 39.4 MB
 *
 * O(n^2)
 */
public class Q32_LongtestValidParenthese {
    public int longestValidParentheses(String s) {
        if(s == null || s.equals("")) {
            return 0;
        }
        int[] mask = new int[s.length()];
        LinkedList<Pivot> pivot = new LinkedList<>();
        Arrays.fill(mask, 0);
        int pivotCount = 0;
        if(s.charAt(0) == '(') {
            pivotCount++;
        }
        for(int i = 1; i < s.length(); i++) {
            if(s.charAt(i) == '(') {
                pivotCount++;
            }
            if(s.charAt(i) == ')') {
                if(s.charAt(i - 1) == '(') {
                    pivot.add(new Pivot(i, pivotCount));
                    //System.out.println(i + "~~~" + pivotCount);
                    mark(mask, i, pivot);
                    pivotCount = 0;
                }
                else {
                    if(pivot.size() == 0) {
                        //System.out.println("xxzzz"+ i);
                    }
                    else {
                        //System.out.println("xxx" + i);
                        mark(mask, i, pivot);
                    }
                }
            }
        }
        int tmp = 0;
        int result = 0;
        for(int i = 0; i < mask.length; i++) {
            //System.out.print(mask[i]);
            if(mask[i] == 0) {
                result = Math.max(result, tmp);
                tmp = 0;
            }
            else {
                tmp++;
            }
        }
        return Math.max(result, tmp);
    }

    void mark(int[] mask, int pos, LinkedList<Pivot> pivots) {
        Pivot p = pivots.peekLast();
        //System.out.println("aaa" + pos + " " + p.pos + "  " + p.count);
        if(p.count > 1) {
            p.count--;
            mask[pos] = 1;
            mask[p.pos - (p.origin - p.count)] = 1;
            //System.out.println("cccc" + (p.pos - (p.origin - p.count)));
        }
        else if(p.count == 1) {
            pivots.pollLast();
            p.count--;
            mask[pos] = 1;
            mask[p.pos - (p.origin - p.count)] = 1;
            //System.out.println("ccc" + (p.pos - (p.origin - p.count)));
        }
        else {

        }
    }



    private class Pivot {
        int pos;
        int count;
        int origin;
        public Pivot(int pos, int count) {
            this.count = count;
            this.pos = pos;
            this.origin = count;
        }
    }
}
