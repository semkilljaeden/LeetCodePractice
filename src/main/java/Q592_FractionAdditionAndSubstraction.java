import java.util.ArrayList;

/***
 * 33mins
 * Runtime: 6 ms, faster than 82.80% of Java online submissions for Fraction Addition and Subtraction.
 * Memory Usage: 38.2 MB, less than 67.54% of Java online submissions for Fraction Addition and Subtraction.
 */
public class Q592_FractionAdditionAndSubstraction {
    public String fractionAddition(String expression) {
        ArrayList<F> f = new ArrayList();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if((c == '+' || c == '-') && sb.length() > 0) {
                f.add(new F(sb.toString()));
                sb.setLength(0);
            }
            sb.append(c);
        }
        if(sb.length() > 0) {
            f.add(new F(sb.toString()));
            sb.setLength(0);
        }
        F result = f.get(0);
        for(int i = 1; i < f.size(); i++) {
            result.add(f.get(i));
        }
        return result.toString();
    }

    public class F {
        int n;
        int d;

        public F(String s) {
            String[] nd = s.split("/");
            n = Integer.valueOf(nd[0]);
            d = Integer.valueOf(nd[1]);
            if(d < 0) {
                n *= -1;
            }
            d = Math.abs(d);
        }

        public void add(F f) {
            n = n * f.d + f.n * d;
            d = d * f.d;
            reduce();
        }

        public void reduce() {
            if(n % d == 0) {
                n /= d;
                d = 1;
                return;
            }
            int[] dv = {2, 3, 5, 7};
            for(int i = 0; i < dv.length; i++) {
                while(n % dv[i] == 0 && d % dv[i] == 0) {
                    n /= dv[i];
                    d /= dv[i];
                }
            }
        }

        public String toString() {
            return n + "/" + d;
        }
    }
}
