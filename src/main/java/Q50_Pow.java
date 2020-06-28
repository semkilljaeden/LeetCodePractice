/***
 * 13mins medium
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Pow(x, n).
 * Memory Usage: 37.9 MB, less than 16.85% of Java online submissions for Pow(x, n).
 */

public class Q50_Pow {
    public double myPow(double x, int n) {
        if(n == 0) {
            return 1;
        }
        double residue = 1;
        if(n == Integer.MIN_VALUE) {
            residue = x;
            n += 1;
        }
        boolean sign = n < 0;
        n = Math.abs(n);
        double result = recurse(x, n);
        if(sign) {
            return 1 / (result * residue);
        }
        return result * residue;
    }

    public double recurse(double x, int n) {
        if(n == 1) {
            return x;
        }
        double residue = n % 2 == 0 ? 1 : x;
        double result = recurse(x, n / 2);
        return residue * result * result;
    }
}
