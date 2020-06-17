/***
 * Runtime: 1 ms 100%
 * Memory Usage: 39.1 MB
 */

public class Q8_Atoi {
    public int myAtoi(String str) {
        int result = 0;
        boolean started = false;
        int sign = 1;
        for(int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if(c == ' ' && !started) {
                continue;
            }
            else if(c == '-' && !started) {
                sign = -1;
                started = true;
            }
            else if(c == '+' && !started) {
                started = true;
            }
            else if(c >= '0' && c <= '9') {
                if(!started) {
                    started = true;
                }
                if(result > Integer.MAX_VALUE / 10 || result == Integer.MAX_VALUE / 10 && c >= '8') {
                    return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
                }
                result *= 10;
                result += (int)c - (int)'0';
            }
            else {
                break;
            }
        }
        return result * sign;
    }
}
