import java.util.Arrays;

/***
 * 10mins
 * Runtime: 4 ms, faster than 98.20% of Java online submissions for First Unique Character in a String.
 * Memory Usage: 39.7 MB, less than 87.54% of Java online submissions for First Unique Character in a String.
 */
public class Q387_FirstUniqueCharacterInAString {
    public int firstUniqChar(String s) {
        int[] mask = new int[26];
        Arrays.fill(mask, -1);
        for(int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'a';
            if(mask[c] >= 0) {
                mask[c] = -2;
            }
            else if(mask[c] != -2) {
                mask[c] = i;
            }
        }
        int result = Integer.MAX_VALUE;
        for(int i = 0; i < 26; i++) {
            if(mask[i] >= 0) {
                result = Math.min(result, mask[i]);
            }
        }
        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
