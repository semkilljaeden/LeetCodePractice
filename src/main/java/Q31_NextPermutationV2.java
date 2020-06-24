import java.util.Arrays;

/***
 * 2mins
 *
 * Key take away:  after swap, even though the value is smaller than the original, but the descending order does not change
 *
 * 10 9 8 7 6 5
 * 10 9 7 7 6 5 ===> same!!! just reverse
 */
public class Q31_NextPermutationV2 {
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
        reverse(nums, i + 1, nums.length);
    }

    public void reverse(int[] nums, int left, int right) {
        int tmp;
        while(left < right) {
            tmp = nums[left];
            nums[left] = nums[right - 1];
            nums[right - 1] = tmp;
            left++;
            right--;
        }
    }
}
