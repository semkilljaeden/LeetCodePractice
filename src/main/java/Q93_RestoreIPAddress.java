import java.util.ArrayList;
import java.util.List;

/***
 *37mins small bug to fix, need to be extra careful on the boundary
 * Runtime: 2 ms, faster than 86.55% of Java online submissions for Restore IP Addresses.
 * Memory Usage: 39.4 MB, less than 79.32% of Java online submissions for Restore IP Addresses.
 *
 *
 */
public class Q93_RestoreIPAddress {
    String s;
    List<String> result;
    public List<String> restoreIpAddresses(String s) {
        //boundary check if s > 3 * 4
        if(s.length() < 4 || s.length() > 3 * 4) {
            return new ArrayList();
        }
        result = new ArrayList();
        this.s = s;
        recurse(0, new StringBuilder(), 0);
        return result;
    }

    public void recurse(int start, StringBuilder r, int count) {
        int length = r.length();
        if(start == s.length() && count < 4) {
            return;
        }
        else if(count == 4 && start == s.length()) {
            r.setLength(r.length() - 1);
            result.add(r.toString());
        }

        for(int i = start + 3 > s.length() ? s.length() : start + 3; i >= start + 1
            /*the bug is I mistakely put it 1 rather than start + 1*/; i--) {
            String digit = s.substring(start, i);
            if(digit.length() >= 2 && digit.charAt(0) == '0' || Integer.parseInt(digit) > 255) {
                continue;
            }
            r.append(digit);
            r.append(".");
            recurse(i, r, count + 1);
            r.setLength(length);
        }
    }
}
