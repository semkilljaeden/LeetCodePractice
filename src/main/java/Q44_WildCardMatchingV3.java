import java.util.Arrays;

/***
 * 17mins
 * Runtime: 20 ms, faster than 73.37% of Java online submissions for Wildcard Matching.
 * Memory Usage: 41.5 MB, less than 12.99% of Java online submissions for Wildcard Matching.
 */
public class Q44_WildCardMatchingV3 {
    char[] s;
    char[] p;
    int[][] memo;
    public boolean isMatch(String s, String p) {
        this.s = s.toCharArray();
        this.p = p.toCharArray();
        memo = new int[s.length() + 1][p.length() + 1];
        for(int i = 0; i < memo.length; i++) {
            Arrays.fill(memo[i], -1);
        }
        return rec(0, 0);
    }


    public boolean rec(int sidx, int pidx) {
        //end condition TODO
        if(sidx == s.length) {
            if(pidx == p.length) {
                memo[sidx][pidx] = 1;
                return true;
            }
            while(pidx < p.length) {
                if(p[pidx] != '*') {
                    memo[sidx][pidx] = 0;
                    return false;
                }
                pidx++;
            }
            memo[sidx][pidx] = 1;
            return true;
        }
        if(pidx == p.length) {
            memo[sidx][pidx] = 0;
            return false;
        }
        if(memo[sidx][pidx] != -1) {
            return memo[sidx][pidx] == 1;
        }
        if(p[pidx] == '?' || p[pidx] == s[sidx]) {
            memo[sidx][pidx] = rec(sidx + 1, pidx + 1) ? 1 : 0;
        }
        else if(p[pidx] == '*') {
            boolean f = rec(sidx + 1, pidx);
            f = f || rec(sidx + 1, pidx + 1);
            f = f || rec(sidx, pidx + 1);
            memo[sidx][pidx] = f ? 1 : 0;
        }
        return memo[sidx][pidx] == 1;
    }
}
