/***
 * Runtime: 1 ms 100%
 * Memory Usage: 36.4 MB
 */

public class Q7_ReverseInteger {
    public int reverse(int x) {
        long rev= 0;
        while( x != 0){
            rev= rev*10 + x % 10;
            x= x/10;
            if( rev > Integer.MAX_VALUE || rev < Integer.MIN_VALUE)
                return 0;
        }
        return (int) rev;
    }
}
