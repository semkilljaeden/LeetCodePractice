import java.lang.reflect.Array;
import java.util.Arrays;

/***
 * 0:36
 * 1:54
 */
public class Q31_NextPermutation {
    public void nextPermutation(int[] nums) {
        int tmp;
        int i = 0;
        for(i = nums.length - 2; i >= 0 && nums[i] >= nums[i + 1]; i--);
        if(i >= 0) {
            boolean hasSwap = false;
            for(int j = i + 1; j < nums.length; j++) {
                if(nums[j] <= nums[i]) {
                    tmp = nums[i];
                    nums[i] = nums[j - 1];
                    nums[j - 1] = tmp;
                    hasSwap = true;
                    break;
                }
            }
            if(!hasSwap) {
                tmp = nums[i];
                nums[i] = nums[nums.length - 1];
                nums[nums.length - 1] = tmp;
            }
        }
        Arrays.sort(nums, i + 1, nums.length);
    }
}
