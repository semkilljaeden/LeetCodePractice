import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/***
 * 1:30 hr
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for First Missing Positive.
 * Memory Usage: 37.1 MB, less than 90.23% of Java online submissions for First Missing Positive.
 */

/***
 * Suppose input has negative values, positive values, and positive values beyond size of input (n).
 * We can easily ignore the negative values firstly. Then the first missing positive must be less than or equal to n.
 * So we try to fill every positive input n' that n' <= n into nums[n' - 1]. Then we iterate the nums again to find the
 * first element that does not match its index.
 *
 * Sample case:
 * origin:            after process:
 *
 * [5, 4, 2, 3, 10000] ==== [5, 4, 2, 3, 5] => [5, 4, 2, 4, 5] 3 => [5, 4, 3, 4, 5], 2 => [5, 2, 3, 4, 5]
 * since 5 - 1 != 0, return 1
 *
 * [-1, 1, 3, 5]  => [1, 1, 3, 5]   so index 1 mismatches, return 2
 *  * [1, 2, 3, 4]  === return 5
 */
public class Q41_FirstMissingPositive {
    public int firstMissingPositive(int[] nums) {
        int tmpValue;
        int fromValue;
        if(nums == null) {
            return 1;
        }
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] < 1 || nums[i] > nums.length || nums[i] == i + 1) {
                continue;
            }
            else {
                fromValue = nums[i];
                while(fromValue > 0 && fromValue <= nums.length && nums[fromValue - 1] != fromValue) {
                    tmpValue = nums[fromValue - 1];
                    nums[fromValue - 1] = fromValue;
                    fromValue = tmpValue;
                }

            }
        }
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.length + 1;
    }
}
