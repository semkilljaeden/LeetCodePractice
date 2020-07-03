import java.util.Arrays;
import java.util.List;

/**
 * 2hr and read the answer... total failure... damn
 * Runtime: 2 ms, faster than 93.95% of Java online submissions for Scramble String.
 * Memory Usage: 39.1 MB, less than 93.48% of Java online submissions for Scramble String.
 *
 *  can be improved by memo
 *
 */
public class Q87_ScrambleString {
    int[] s1C = new int[26];
    int[] s2C = new int[26];
    public boolean isScramble(String s1, String s2) {
        return recurse(s1, s2);
    }
    public boolean recurse(String s1, String s2) {
        if(!isAnagram(s1, s2)) {
            return false;
        }
        if(s1.equals(s2)) {
            return true;
        }
        for(int i = 0; i < s1.length() - 1; i++) {
            boolean tmp = recurse(s1.substring(0, i + 1), s2.substring(0, i + 1))
                    && recurse(s1.substring(i + 1), s2.substring(i + 1))
                    || recurse(s1.substring(0, i + 1), s2.substring(s2.length() - i - 1))
                    && recurse(s1.substring(i + 1), s2.substring(0, s2.length() - i - 1));
            if(tmp == true) {
                return true;
            }
        }
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
