import java.util.Arrays;

/***
 * 2hr, over-thinking.....
 * Runtime: 12 ms, faster than 54.34% of Java online submissions for Longest Common Subsequence.
 * Memory Usage: 43.2 MB, less than 66.92% of Java online submissions for Longest Common Subsequence.
 */
public class Q1143_LongestCommonSubsequence {
    int[][] memo;
    char[] t1;
    char[] t2;
    public int longestCommonSubsequence(String text1, String text2) {
        t1 = text1.toCharArray();
        t2 = text2.toCharArray();
        memo = new int[text1.length() + 1][text2.length() + 1];
        for(int i = 0; i < memo.length - 1; i++) {
            Arrays.fill(memo[i], -1);
            memo[i][memo[0].length - 1] = 0;
        }
        return rec(0, 0);
    }


    public int rec(int i1, int i2) {
        if(i1 >= t1.length || i2 >= t2.length) {
            return 0;
        }
        if(memo[i1][i2] != -1) {
            return memo[i1][i2];
        }
        if(t1[i1] == t2[i2]) {
            memo[i1][i2] = 1 + rec(i1 + 1, i2 + 1);
            return memo[i1][i2];
        }
        memo[i1][i2] = Math.max(rec(i1 + 1, i2), rec(i1, i2 + 1));
        return memo[i1][i2];
    }
}
