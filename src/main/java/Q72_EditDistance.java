import java.util.Arrays;
import java.util.LinkedList;

/***
 * 30mins one shot AC hard
 * Runtime: 10 ms, faster than 9.94% of Java online submissions for Edit Distance.
 * Memory Usage: 40.7 MB, less than 9.25% of Java online submissions for Edit Distance.
 */
public class Q72_EditDistance {
    public int minDistance(String word1, String word2) {
        //check boundary
        if(word1.length() == 0) {
            return word2.length();
        }
        if(word2.length() == 0) {
            return word1.length();
        }
        int[][] memo = new int[word1.length() + 1][word2.length() + 1];
        for(int i = 0; i < memo.length; i++) {
            memo[i][0] = i;
        }
        for(int i = 0; i < memo[0].length; i++) {
            memo[0][i] = i;
        }
        memo[0][0] = 0;
        for(int i = 1; i < memo.length; i++) {
            for(int j = 1; j < memo[0].length; j++) {
                /***
                 * int[] r = new int[] {memo[i - 1][j - 1] + (word1.charAt(i - 1) == word2.charAt(j - 1) ? 0 : 1),
                 *         memo[i - 1][j] + 1,
                 *         memo[i][j - 1] + 1};
                 * Arrays.sort(r);
                 * memo[i][j] = r[0]; // slow
                 */
                memo[i][j] = Math.min(memo[i - 1][j] + 1,
                        Math.min(memo[i - 1][j - 1] + (word1.charAt(i - 1) == word2.charAt(j - 1) ? 0 : 1), memo[i][j - 1] + 1));



            }
        }
        return memo[word1.length()][word2.length()];
    }
}
