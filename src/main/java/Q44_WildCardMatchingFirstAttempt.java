/***
 * 0:04
 * 0:20  out of limit, need optimization
 */
public class Q44_WildCardMatchingFirstAttempt {
    public boolean isMatch(String s, String p) {
        return recurse(s, 0, p, 0);
    }

    public boolean recurse(String s, int i, String p, int j) {
        boolean result = false;
        if(i == s.length()) {
            return j >= p.length() || j <= p.length() - 1 && p.substring(j).replace("*", "").equals("");
        }
        else if(j == p.length()) {
            return i == s.length();
        }
        if(p.charAt(j) == '?') {
            result |= recurse(s, i + 1, p, j + 1);
        }
        else if(p.charAt(j) == '*') {
            result |= recurse(s, i + 1, p, j + 1);
            result |= recurse(s, i + 1, p, j);
            result |= recurse(s, i, p, j + 1);
        }
        else if(p.charAt(j) == s.charAt(i)) {
            result |= recurse(s, i + 1, p, j + 1);
        }
        return result;
    }
}
