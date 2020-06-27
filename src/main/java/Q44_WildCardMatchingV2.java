import java.util.Arrays;

/***
 * funny 99% DP then did not realize it nearly works and goes into wrong direction, damn,
 * finally get this correct
 *
 * Runtime: 26 ms, faster than 52.56% of Java online submissions for Wildcard Matching.
 * Memory Usage: 41.9 MB, less than 18.95% of Java online submissions for Wildcard Matching.
 */
public class Q44_WildCardMatchingV2 {
    public boolean isMatch(String s, String p) {
        if(s.equals(p)) {
            return true;
        }
        else if(p.equals("")) {
            return false;
        }
        StringBuilder sanitzedP = new StringBuilder();
        sanitzedP.append(p.charAt(0));
        for(int i = 1; i < p.length(); i++) {
            if(p.charAt(i) == '*' && p.charAt(i - 1) == '*') {
                continue;
            }
            sanitzedP.append(p.charAt(i));
        }
        p = sanitzedP.toString();
        if(p.equals("*")) {
            return true;
        }
        else if(s.equals("")) {
            return false;
        }
        memo = new int[s.length() + 1][p.length() + 1];
        for(int i = 0; i < memo.length; i++) {
            Arrays.fill(memo[i], -1);
        }
        return recurse(s, 0, p, 0);
    }
    int[][] memo;
    public boolean recurse(String s, int i, String p, int j) {
        boolean result = false;
        if(i == s.length()) {
            memo[i][j] = (j >= p.length() || j <= p.length() - 1 && p.substring(j).replace("*", "").equals("")) ? 1 : 0;
            return memo[i][j] == 1;
        }
        else if(j == p.length()) {
            memo[i][j] = i == s.length() ? 1 : 0;
            return memo[i][j] == 1;
        }
        if(p.charAt(j) == '?' || p.charAt(j) == s.charAt(i)) {
            if(memo[i + 1][j + 1] > -1) {
                result |= memo[i + 1][j + 1] == 1;
            }
            else {
                result |= recurse(s, i + 1, p, j + 1);
            }
        }
        else if(p.charAt(j) == '*') {
            if(memo[i + 1][j + 1] > -1) {
                result |= memo[i + 1][j + 1] == 1;
            }
            else {
                result |= recurse(s, i + 1, p, j + 1);
            }
            if(memo[i + 1][j] > -1) {
                result |= memo[i + 1][j] == 1;
            }
            else {
                result |= recurse(s, i + 1, p, j);
            }
            if(memo[i][j + 1] > -1) {
                result |= memo[i][j + 1] == 1;
            }
            else {
                result |= recurse(s, i, p, j + 1);
            }
        }
        memo[i][j] = result ? 1 : 0;
        return result;
    }
}
