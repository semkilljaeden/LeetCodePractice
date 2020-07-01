/***
 * 16mins
 * Runtime: 1 ms, faster than 100.00% of Java online submissions for Sqrt(x).
 * Memory Usage: 36.2 MB, less than 98.85% of Java online submissions for Sqrt(x).
 */
public class Q69_Sqrt {
    public int mySqrt(int x) {
        //edge cases
        if(x == 0) {
            return 0;
        }
        if(x == 1 || x == 2 || x == 3) {
            return 1;
        }

        long left = 0;
        long right = x;
        long mid = left + (right - left) / 2;
        while(left <= right) {//need to check
            mid = left + (right - left) / 2;
            if((mid * mid) > x) {
                right = mid - 1;
            }
            else if((mid * mid) < x) {
                left = mid + 1;
            }
            else {
                return (int)mid;
            }
        }
        if(mid * mid > x) {
            mid--;
        }
        return (int)mid;
    }
}
