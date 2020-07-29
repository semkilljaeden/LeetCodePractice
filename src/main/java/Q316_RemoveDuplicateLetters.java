/***
 * failed, read the answer
 * Runtime: 11 ms, faster than 18.56% of Java online submissions for Remove Duplicate Letters.
 * Memory Usage: 41.6 MB, less than 5.79% of Java online submissions for Remove Duplicate Letters.
 */
public class Q316_RemoveDuplicateLetters {
    StringBuilder sb = new StringBuilder();
    public String removeDuplicateLetters(String s) {
        rec(s);
        return sb.toString();
    }

    public void rec(String s) {
        if(s.length() == 0) {
            return;
        }
        int[] bucket = new int[26];
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            bucket[c - 'a']++;
        }
        int pos = 0;
        if(--bucket[s.charAt(0) - 'a'] > 0) {
            for(int i = 1; i < s.length(); i++) {
                char c = s.charAt(i);
                if(c < s.charAt(pos)) {
                    pos = i;
                }
                if(--bucket[c - 'a'] == 0) {
                    break;
                }
            }

        }
        sb.append(s.charAt(pos));
        rec(s.substring(pos + 1).replace("" + s.charAt(pos), ""));
    }
}
