/***
 *16:52
 * 17:08 recursion is done
 * 	2719 ms	37.2 MB
 *
 * 	17:09 dp opti
 * 	17:13 dp done
 *
 * 	ALL ONE SHOT AC
 * 	Runtime: 4 ms, faster than 51.24% of Java online submissions for Interleaving String.
 * Memory Usage: 54.7 MB, less than 5.06% of Java online submissions for Interleaving String.
 *
 * 17:17 better dp
 * no need s3 dimension
 *
 * Overall: 26mins, Hard, One shot AC
 * Runtime: 1 ms, faster than 90.41% of Java online submissions for Interleaving String.
 * Memory Usage: 37.8 MB, less than 52.91% of Java online submissions for Interleaving String.
 */

public class Q97_InterleavingString {
    String s1;
    String s2;
    String s3;
    int[][] memo;
    public boolean isInterleave(String s1, String s2, String s3) {
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;

        memo = new int[s1.length() + 1][s2.length() + 1];
        return rec(0, 0, 0);
    }

    public boolean rec(int s1p, int s2p, int s3p) {
        if(s3p == s3.length() && s2p == s2.length() && s1p == s1.length()) {
            return true;
        }
        else if(s3p < s3.length() && s2p == s2.length() && s1p == s1.length()) {
            return false;
        }
        else if(s3p >= s3.length() && s2p < s2.length() && s1p < s1.length()) {
            return false;
        }
        if(memo[s1p][s2p] != 0) {
            return memo[s1p][s2p] ==  1;
        }
        char s1c = s1p < s1.length() ? s1.charAt(s1p) : 0;
        char s2c = s2p < s2.length() ? s2.charAt(s2p) : 1;
        char s3c = s3p < s3.length() ? s3.charAt(s3p) : 2;
        boolean result = false;
        if(s3c != s1c && s3c != s2c) {
            memo[s1p][s2p] = -1;
            return false;
        }
        if(s3c == s1c) {
            result = rec(s1p + 1, s2p, s3p + 1);
            if(result) {
                memo[s1p][s2p] = 1;
                return true;
            }
        }
        if(s3c == s2c) {
            result |= rec(s1p, s2p + 1, s3p + 1);
        }
        memo[s1p][s2p] = result ? 1 : -1;
        return result;
    }
}
