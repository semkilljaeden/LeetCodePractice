import java.util.Arrays;

/***
 * 2hr, over-thinking.....
 * Runtime: 12 ms, faster than 54.34% of Java online submissions for Longest Common Subsequence.
 * Memory Usage: 43.2 MB, less than 66.92% of Java online submissions for Longest Common Subsequence.
 */
public class Q1143_LongestCommonSubsequenceV2 {
    char[] t1;
    char[] t2;
    int[][] memo;
    public int longestCommonSubsequence(String text1, String text2) {
        if(text1.length() == 0 || text2.length() == 0) {
            return 0;
        }
        t1 = text1.toCharArray();
        t2 = text2.toCharArray();
        memo = new int[t1.length][t2.length];
        for(int i = 0; i < memo.length; i++) {
            Arrays.fill(memo[i], -1);
        }
        return rec(0, 0);
    }

    int rec(int i1, int i2) {
        if(i1 >= t1.length || i2 >= t2.length) {
            return 0;
        }
        if(memo[i1][i2] > -1) {
            return memo[i1][i2];
        }
        if(t1[i1] == t2[i2]) {
            memo[i1][i2] = 1 + rec(i1 + 1, i2 + 1);
        }
        else {
            memo[i1][i2] = Math.max(rec(i1 + 1, i2), rec(i1, i2 + 1));
        }
        return memo[i1][i2];
    }
}
