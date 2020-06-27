/***
 * 1:26mins medium, a bit slow
 * Runtime: 15 ms, faster than 19.02% of Java online submissions for Multiply Strings.
 * Memory Usage: 43.1 MB, less than 5.04% of Java online submissions for Multiply Strings.
 *
 * use int[] as buffer to avoid reverse
 */

public class Q43_MultiplyStrings {
    public String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        int carryForward = 0;
        String prev = "";
        StringBuilder sb = new StringBuilder();
        int result = 0;
        for(int i = num1.length() - 1; i >= 0; i--) {
            carryForward = 0;
            sb.setLength(0);
            for(int j = num2.length() - 1; j >= 0; j--) {
                result = (num1.charAt(i) - '0') * (num2.charAt(j) - '0') + carryForward;
                carryForward = result / 10;
                sb.append((char)(result - carryForward * 10+ '0'));
            }
            if(carryForward > 0) {
                sb.append(carryForward);
            }
            String curr = sb.reverse().toString();
            prev = add(prev, curr, num1.length() - i - 1);
        }
        return prev;
    }

    public String add(String prev, String curr, int multiplier) {
        if(prev == "") return curr;
        StringBuilder sb = new StringBuilder();
        sb.append(prev.substring(prev.length() - multiplier)).reverse();
        prev = prev.substring(0, prev.length() - multiplier);
        int carryForward = 0;
        int result = 0;
        int i = prev.length() - 1;
        int j = curr.length() - 1;
        while(i >= 0 && j >= 0) {
            result = prev.charAt(i--) - '0' + carryForward + curr.charAt(j--) - '0';
            carryForward = result / 10;
            sb.append((char)(result - carryForward * 10+ '0'));
        }
        String reminder = i > j ? prev : curr;
        for(j = Math.abs(i - j) - 1; j >=0; j--) {
            result = (reminder.charAt(j) - '0')  + carryForward;
            carryForward = result / 10;
            sb.append((char)(result - carryForward * 10+ '0'));
        }
        if(carryForward > 0) {
            sb.append(carryForward);
        }
        return sb.reverse().toString();
    }

}
