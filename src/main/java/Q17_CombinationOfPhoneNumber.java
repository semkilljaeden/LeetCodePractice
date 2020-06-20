import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/***
 * Duration: 24mins
 *
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Letter Combinations of a Phone Number.
 * Memory Usage: 38.2 MB, less than 83.99% of Java online submissions for Letter Combinations of a Phone Number
 */

public class Q17_CombinationOfPhoneNumber {
    String digits;
    List<String> result;
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0) {
            return new LinkedList<>();
        }
        this.digits = digits;
        result = new LinkedList<String>();
        addLetter(0, new StringBuilder());
        return result;
    }

    public void addLetter(int index, StringBuilder sb) {
        if(index >= digits.length()) {
            result.add(sb.toString());
            return;
        }
        int digit = digits.charAt(index) - '0' - 2;
        int i = 0;
        int prefix = digit * 3;
        if(digit == 6 || digit == 7) {
            prefix += 1;
        }
        for(; i < 3; i++) {
            addLetter(index + 1, new StringBuilder(sb).append((char)(prefix + 'a' + i)));
        }
        if(digit == 5 || digit == 7) {
            addLetter(index + 1, new StringBuilder(sb).append((char)(prefix + 'a' + i)));
        }
    }
}
