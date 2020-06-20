import java.util.*;

/***
 * 29ms, 21.42%
 *
 * 42.4MB 6.17%
 */
public class Q18_4Sum {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new LinkedList<>();
        HashSet<String> set = new HashSet<>();
        Arrays.sort(nums);
        int leftMid;
        int rightMid;
        int tmp;
        for(int left = 0; left < nums.length - 3; left++) {
            for(int right = nums.length - 1; right > left + 1; right--) {
                leftMid = left + 1;
                rightMid = right - 1;
                while(leftMid < rightMid) {
                    tmp = nums[left] + nums[leftMid] + nums[rightMid] + nums[right];
                    if(tmp < target) {
                        leftMid++;
                    }
                    else if(tmp > target) {
                        rightMid--;
                    }
                    else {
                        String c = new StringBuilder().append(nums[left]).append(nums[leftMid]).append(nums[rightMid]).append(nums[right]).toString();
                        if(!set.contains(c)) {
                            result.add(Arrays.asList(nums[left], nums[leftMid], nums[rightMid], nums[right]));
                            set.add(c);
                        }

                        leftMid++;
                        rightMid--;
                    }
                }
            }
        }
        return new ArrayList<>(result);
    }
}
