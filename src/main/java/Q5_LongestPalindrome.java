/***
 * Runtime: 260 ms  11.43%
 * Memory Usage: 42.4 MB
 */

public class Q5_LongestPalindrome {
    public String longestPalindrome(String s) {
        String result = "";
        StringBuilder sb = new StringBuilder(1000);
        for(int i = 0; i < s.length(); i++) {
            int left = i - 1;
            int right = i + 1;
            sb.append(s.charAt(i));
            if(right >= s.length()) {
                result = sb.length() > result.length() ? sb.toString() : result;
                return result;
            }
            if(s.charAt(i) == s.charAt(right)) {
                sb.append(s.charAt(right));
                check(s, left, right + 1, sb);
            }
            result = sb.length() > result.length() ? sb.toString() : result;
            sb.setLength(0);
            sb.append(s.charAt(i));
            check(s, left, right, sb);
            result = sb.length() > result.length() ? sb.toString() : result;
            sb.setLength(0);
        }
        return result;
    }

    public void check(String s, int left, int right, StringBuilder sb) {
        while(left >= 0 && right < s.length()) {

            char leftC = s.charAt(left);
            char rightC = s.charAt(right);
            if(leftC == rightC) {
                sb.insert(0, leftC);
                sb.append(rightC);
                left--;
                right++;
            }
            else {
                break;
            }
        }
    }
}
