import java.util.Arrays;

/***
 * 34mins medium
 * Runtime: 1 ms, faster than 83.76% of Java online submissions for Longest Substring with At Least K Repeating Characters.
 * Memory Usage: 39.4 MB, less than 26.25% of Java online submissions for Longest Substring with At Least K Repeating Characters.
 * can be further optimized by using char array and index instead of copying strings
 *
 */
public class Q395_LongestSubstringwithAtLeastKRepeatingCharacters {
    int k;
    int result = 0;
    public int longestSubstring(String s, int k) {
        this.k = k;
        rec(s);
        return result;
    }

    public void rec(String s) {
        if(s == null || s.length() == 0) {
            return;
        }
        int[] bs = new int[26];
        Arrays.fill(bs, 0);
        char[] c = s.toCharArray();
        for(int i = 0; i < c.length; i++) {
            bs[c[i] - 'a']++;
        }
        boolean flag = true;
        for(int i = 0; i < 26; i++) {
            if(bs[i] != 0 && bs[i] < k) {
                flag = false;
            }
        }
        if(flag) {
            result = Math.max(result, s.length());
            return;
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < c.length; i++) {
            if(bs[c[i] - 'a'] < k) {
                rec(sb.toString());
                sb.setLength(0);
            }
            else {
                sb.append(c[i]);
            }
        }
        if(sb.length() > 0) {
            rec(sb.toString());
        }
    }
}
