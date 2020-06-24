public class Q29_DivideTwoInteger {
    public int divide(int dividend, int divisor) {
        if(dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        if(dividend == Integer.MIN_VALUE && divisor == 1) {
            return Integer.MIN_VALUE;
        }
        int d;
        int result = 0;
        int partialResult;
        boolean isNegative = (dividend > 0 ? 1 : -1) + (divisor > 0 ? 1 : -1) == 0;
        dividend = dividend == Integer.MIN_VALUE ? Integer.MIN_VALUE : 0 - Math.abs(dividend);
        divisor = divisor == Integer.MIN_VALUE ? Integer.MIN_VALUE : 0 - Math.abs(divisor);
        if(dividend == divisor) {
            return isNegative ? -1 : 1;
        }
        if(divisor == -1) {
            return isNegative ? dividend : 0 - dividend;
        }
        while(dividend < divisor) {
            d = divisor;
            partialResult = 1;
            result += partialResult;
            dividend -= d;
            d = d << 1;
            partialResult = partialResult << 1;
            while(dividend < d && d < 0) {
                dividend -= d;
                result += partialResult;
                d = d << 1;
                partialResult = partialResult << 1;
            }
            System.out.println(result);
        }

        return isNegative ? 0 - result : result;
    }
}
