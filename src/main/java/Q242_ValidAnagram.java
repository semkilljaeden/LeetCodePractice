import java.util.Arrays;

/***
 * 3mins, not the best solution
 * Runtime: 2 ms, faster than 96.34% of Java online submissions for Valid Anagram.
 * Memory Usage: 39.6 MB, less than 65.36% of Java online submissions for Valid Anagram.
 *
 * can use bucket sort.... damn, did not think of this
 */
public class Q242_ValidAnagram {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) {
            return false;
        }
        char[] sc = s.toCharArray();
        char[] tc = t.toCharArray();
        Arrays.sort(sc);
        Arrays.sort(tc);
        for(int i = 0; i < sc.length; i++) {
            if(sc[i] != tc[i]) {
                return false;
            }
        }
        return true;
    }
}
