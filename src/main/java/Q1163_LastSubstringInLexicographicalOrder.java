/***
 *
 */
public class Q1163_LastSubstringInLexicographicalOrder {
    public String lastSubstring(String s) {
        if(s.length() == 0) {
            return s;
        }
        int[] c = new int[26];
        char[] sc = s.toCharArray();
        for(int i = 0; i < sc.length; i++) {
            c[sc[i] - 'a']++;
        }
        int lc = 25;
        for(int i = 25; i >= 0; i--) {
            if(c[i] > 0) {
                lc = i;
                break;
            }
        }
        int prev = sc.length - 1;
        for(int i = sc.length - 1; i >= 0; i--) {
            if(sc[i] - 'a' == lc && c[lc] >= 0) {
                int size = (prev - i) > (sc.length - 1 - prev) ? sc.length - 1 - prev :prev - i;
                if(s.substring(i, i + size + 1).compareTo(s.substring(prev, prev + size + 1)) > 0) {
                    prev = i;
                }
                c[lc]--;
            }
        }
        return s.substring(prev);
    }
}
