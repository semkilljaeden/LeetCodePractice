/***
 * Recursion Version
 *
 * 1469 ms 5.04%
 * 37.8 MB 96.47%
 */

public class Q10_RegularExpressionV2 {
    public boolean isMatch(String s, String p) {
        return match(s, 0, p, 0);
    }

    public boolean match(String s, int sIndex, String p, int pIndex) {
        if(sIndex >= s.length()) {
            if(pIndex >= p.length()) {
                return true;
            }
            else {
                while(pIndex <= p.length() - 1) {
                    if(p.charAt(pIndex) == '*') {
                        return false;
                    }
                    else if(pIndex + 1 >= p.length() || p.charAt(pIndex + 1) != '*') {
                        return false;
                    }
                    pIndex += 2;
                }
                return true;
            }
        }
        else if(p.length() <= pIndex) {
            return false;
        }

        boolean isLocalMatch = p.charAt(pIndex) == '.' || p.charAt(pIndex) == s.charAt(sIndex);
        if(pIndex + 1 < p.length() && p.charAt(pIndex + 1) == '*') {
            return (isLocalMatch &&
                    (match(s, sIndex + 1, p, pIndex + 2)
                            || match(s, sIndex + 1, p, pIndex)))
                    || match(s, sIndex, p, pIndex + 2);
        }
        else {
            return isLocalMatch && match(s, sIndex + 1, p, pIndex + 1);
        }
    }
}
