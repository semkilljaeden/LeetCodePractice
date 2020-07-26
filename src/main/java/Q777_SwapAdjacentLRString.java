/***
 * 19:53
 * bad question. Not going to do, read the solution, just memorize the solution...
 * Runtime: 4 ms, faster than 83.20% of Java online submissions for Swap Adjacent in LR String.
 * Memory Usage: 39.6 MB, less than 40.50% of Java online submissions for Swap Adjacent in LR String.
 */
public class Q777_SwapAdjacentLRString {
    public boolean canTransform(String start, String end) {
        if(start.length() != end.length() || !start.replace("X", "").equals(end.replace("X", ""))) {
            return false;
        }

        char[] s = start.toCharArray();
        char[] e = end.toCharArray();
        int t = 0;
        int i = 0;
        for(i = 0; i < s.length; i++) {
            if(s[i] == 'X' || s[i] == 'R') {
                continue;
            }
            while(e[t] != 'L' && t < s.length) {
                t++;
            }
            if(t > i || t >= s.length) {
                return false;
            }
            else {
                t++;
            }
        }
        t = s.length - 1;
        i = s.length - 1;
        for(i = s.length - 1; i >= 0; i--) {
            if(s[i] == 'X' || s[i] == 'L') {
                continue;
            }
            while(e[t] != 'R' && t >= 0) {
                t--;
            }
            if(t < i || t < 0) {
                return false;
            }
            else {
                t--;
            }
        }
        return true;
    }
}
