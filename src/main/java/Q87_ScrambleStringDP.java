import java.util.Arrays;

/**
 * 2hr and read the answer... total failure... damn
 * Runtime: 3 ms, faster than 59.77% of Java online submissions for Scramble String.
 * Memory Usage: 39.1 MB, less than 93.48% of Java online submissions for Scramble String.
 *
 *  DP is actually slower...
 *  
 */
public class Q87_ScrambleStringDP {
    int[] s1C = new int[26];
    int[] s2C = new int[26];
    int[][][] memo; //yes
    String s1;
    String s2;
    public boolean isScramble(String s1, String s2) {
        this.s1 = s1;
        this.s2 = s2;
        memo = new int[s1.length()][s2.length()][s1.length() + 1];
        return recurse(0, 0, s1.length());
    }
    public boolean recurse(int s1s, int s2s, int len) {
        if(memo[s1s][s2s][len] != 0) {
            return memo[s1s][s2s][len] == 1;
        }
        if(!isAnagram(s1.substring(s1s, s1s + len), s2.substring(s2s, s2s + len))) {
            memo[s1s][s2s][len] = -1;
            return false;
        }
        if(len == 1 && s1.substring(s1s, s1s + len).equals(s2.substring(s2s, s2s + len))) {
            memo[s1s][s2s][len] = 1;
            return true;
        }
        //len = s1.length()
        for(int i = 0; i < len - 1; i++) {
            boolean result = recurse(s1s, s2s, i + 1)
                    && recurse(s1s + i + 1, s2s + i + 1, len - i - 1)
                    || recurse(s1s, s2s + len - i - 1, i + 1)
                    && recurse(s1s + i + 1, s2s, len - i - 1);
            if(result) {
                memo[s1s][s2s][len] = 1;
                return true;
            }
        }
        memo[s1s][s2s][len] = -1;
        return false;
    }


    public boolean isAnagram(String s1, String s2) {
        Arrays.fill(s1C, 0);
        Arrays.fill(s2C, 0);
        for(int i = 0; i < s1.length(); i++) {
            s1C[s1.charAt(i) - 'a']++;
            s2C[s2.charAt(i) - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(s1C[i] != s2C[i]) {
                return false;
            }
        }
        return true;
    }
}
