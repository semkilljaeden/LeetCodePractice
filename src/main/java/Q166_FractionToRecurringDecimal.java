import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;

/***
 * 48mins, medium, annoying corner case
 * Runtime: 2 ms, faster than 45.09% of Java online submissions for Fraction to Recurring Decimal.
 * Memory Usage: 38.8 MB, less than 18.41% of Java online submissions for Fraction to Recurring Decimal.
 */
public class Q166_FractionToRecurringDecimal {
    public String fractionToDecimal(int numerator, int denominator) {
        StringBuilder sb = new StringBuilder();
        //integer
        if(numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0) {
            sb.append('-');
        }
        long n = numerator > 0 ? -Math.abs(numerator) : numerator;
        long d = denominator > 0 ? -Math.abs(denominator) : denominator;
        sb.append(n / d);
        long reminder = n % d;
        if(reminder == 0) {
            return sb.toString();
        }
        sb.append('.');
        StringBuilder f = new StringBuilder();
        HashMap<Long, Integer> pos = new HashMap();
        while(!pos.containsKey(reminder) && reminder != 0) {
            pos.put(reminder, f.length());
            reminder *= 10;
            while(reminder > d) {
                reminder *= 10;
                f.append(0);
            }
            f.append(reminder / d);
            reminder %= d;
        }
        if(reminder == 0) {
            return sb.append(f.toString()).toString();
        }
        else {
            String dd = f.toString();
            int pp = pos.get(reminder);
            sb.append(dd.substring(0, pp));
            sb.append('(');
            sb.append(dd.substring(pp));
            sb.append(')');
            return sb.toString();
        }
    }
}
