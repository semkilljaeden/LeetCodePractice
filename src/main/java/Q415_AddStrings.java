/***
 * 8mins easy
 * Runtime: 1 ms, faster than 100.00% of Java online submissions for Add Strings.
 * Memory Usage: 39.8 MB, less than 24.00% of Java online submissions for Add Strings.
 */
public class Q415_AddStrings {
    public String addStrings(String num1, String num2) {
        char[] n1 = num1.length() <= num2.length() ? num1.toCharArray() : num2.toCharArray();
        char[] n2 = num1.length() > num2.length() ? num1.toCharArray() : num2.toCharArray();
        StringBuilder sb = new StringBuilder();
        int reminder = 0;
        int i = n1.length - 1;
        int j = n2.length - 1;
        int tmp = 0;
        while(i >= 0) {
            tmp = n1[i--] + n2[j--] - '0' * 2;
            tmp += reminder;
            reminder = tmp >= 10 ? 1 : 0;
            tmp %= 10;
            sb.append(tmp);
        }
        while(j >= 0) {
            tmp = n2[j--] - '0';
            tmp += reminder;
            reminder = tmp >= 10 ? 1 : 0;
            tmp %= 10;
            sb.append(tmp);
        }
        if(reminder == 1) {
            sb.append(1);
        }
        return sb.reverse().toString();
    }
}
