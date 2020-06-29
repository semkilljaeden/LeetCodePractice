import java.util.Arrays;
import java.util.function.BiPredicate;
import java.util.function.Predicate;

/***
 * 2hr 20mins, this is a bad question, not worthy to do, waste of time
 * Runtime: 3 ms, faster than 40.29% of Java online submissions for Valid Number.
 * Memory Usage: 40.1 MB, less than 26.12% of Java online submissions for Valid Number.
 * Next challenges:
 */
public class Q65_ValidNumber {
    //[+|-]+[0-9]*[.]+[0-9]*[e-|e+|e][0-9]*
    public boolean isNumber(String s) {
        s = s.trim();
        if(s.length() == 0) {
            return false;
        }
        if(s.length() == 1) {
            char c = s.charAt(0);
            return c <= '9' && c >= '0';
        }
        if(s.charAt(0) == '+' || s.charAt(0) == '-') {
            s = s.substring(1);
        }
        if(s.length() == 0) {
            return false;
        }
        if(s.length() == 1) {
            char c = s.charAt(0);
            return c <= '9' && c >= '0';
        }
        return regex1(1, s, 0) || regex2(0, s, 0);
    }



    //[+|-]+[0-9]*[.]+[0-9]*[e]+[+|-]+[0-9]*
    public boolean regex1(int p, String s, int i) {
        if(i >= s.length()) {
            return p == 1 || p == 8 || p == 4;
        }
        char c = s.charAt(i);
        switch(p) {
            case 1:
                if(c <= '9' && c >= '0') {
                    return regex1(1, s, i + 1) || regex1(2, s, i + 1);
                }
                else {
                    return false;
                }
            case 2:
                if(c == '.') {
                    return regex1(4, s, i + 1);
                }
                else {
                    return regex1(5, s, i);
                }
            case 4:
                if(c <= '9' && c >= '0') {
                    return regex1(4, s, i + 1) || regex1(5, s, i + 1);
                }
                else {
                    return regex1(5, s, i);
                }
            case 5:
                if(c == 'e') {
                    return regex1(6, s, i + 1);
                }
                else {
                    return regex1(7, s, i);
                }
            case 6:
                if(c == '+' || c == '-') {
                    return regex1(7, s, i + 1);
                }
                else {
                    return regex1(7, s, i);
                }
            case 7:
                if(c <= '9' && c >= '0') {
                    return regex1(7, s, i + 1) || regex1(8, s, i + 1);
                }
                else {
                    return false;
                }
                //check end of string
            case 8:
                return i == s.length();

            default:
                return false;
        }
    }

    //[+|-]+[.]+[0-9]*[e]+[+|-]+[0-9]*
    public boolean regex2(int p, String s, int i) {
        if(i >= s.length()) {
            return p == 1 || p == 5;
        }
        char c = s.charAt(i);
        switch(p) {
            case 0:
                if(c == '.') {
                    return regex2(1, s, i + 1);
                }
                else {
                    return false;
                }
            case 1:
                if(c <= '9' && c >= '0') {
                    return regex2(1, s, i + 1) || regex2(2, s, i + 1);
                }
                else {
                    return false;
                }
            case 2:
                if(c == 'e') {
                    return regex2(3, s, i + 1);
                }
                else {
                    return regex2(4, s, i);
                }
            case 3:
                if(c == '+' || c == '-') {
                    return regex1(4, s, i + 1);
                }
                else {
                    return regex1(4, s, i);
                }
            case 4:
                if(c <= '9' && c >= '0') {
                    return regex2(4, s, i + 1) || regex2(5, s, i + 1);
                }
                else {
                    return false;
                }
                //check end of string
            case 5:
                return i == s.length(); // check has done at the beginning of the method

            default:
                return false;
        }
    }
}
