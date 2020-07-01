import java.util.Arrays;

/***
 *10mins Runtime: 0 ms, faster than 100.00% of Java online submissions for Plus One.
 * Memory Usage: 37.8 MB, less than 69.35% of Java online submissions for Plus One.
 */
public class Q66_PlusOne {
    public int[] plusOne(int[] digits) {
        int reminder = 0;
        digits[digits.length - 1] += 1;
        reminder = digits[digits.length - 1] / 10;
        digits[digits.length - 1] %= 10;
        for(int i = digits.length - 2; i >= 0; i--){
            digits[i] += reminder;
            reminder = digits[i] / 10;
            digits[i] %= 10;
        }
        if(reminder == 1) {
            int[] result = new int[digits.length + 1];
            for(int i = 1; i < result.length; i++){
                result[i] = digits[i - 1];
            }
            result[0] = 1;
            digits = result;
        }
        return digits;

    }
}
