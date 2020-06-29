/***
 * 10mins easy
 *Runtime: 0 ms, faster than 100.00% of Java online submissions for Length of Last Word.
 * Memory Usage: 37.7 MB, less than 55.34% of Java online submissions for Length of Last Word.
 */
public class Q58_LengthOfLastWord {
    public int lengthOfLastWord(String s) {
        int length = 0;
        int i = s.length() - 1;
        for(; i >= 0 &&
                ((s.charAt(i) < 'a' || s.charAt(i) > 'z') &&
                        (s.charAt(i) < 'A'
                                || s.charAt(i) > 'Z')); i--);
        for(; i >= 0; i--) {
            if(s.charAt(i) >= 'a' && s.charAt(i) <= 'z' ||
                    s.charAt(i) >= 'A'
                            && s.charAt(i) <= 'Z') {
                length++;
            }
            else {
                return length;
            }
        }
        return length;
    }
}
