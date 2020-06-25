/***
 * 1hr medium a bit slow
 *
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Search in Rotated Sorted Array.
 * Memory Usage: 39.1 MB, less than 61.70% of Java online submissions for Search in Rotated Sorted Array.
 *
 * Binary search ====> left = mid + 1 ; right = mid - 1   save two logic condition
 */


public class Q33_SearchInRotatedSortedArray {
    public int search(int[] nums, int target) {
        if(nums == null || nums.length == 0) {
            return -1;
        }
        int left = 0;
        int right = nums.length - 1;
        int mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(target > nums[mid]) {
                if(nums[mid] >= nums[0]) {
                    left = mid + 1;
                }
                else {
                    if(target >= nums[0] && nums[nums.length - 1] < nums[0]) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
            }
            else {
                if(nums[mid] < nums[0]) {
                    right = mid - 1;
                }
                else {

                    if(target <= nums[nums.length - 1] && nums[nums.length - 1] < nums[0]) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
            }

        }
        return  -1;
    }

    public int search2(int[] nums, int target) {
        if(nums == null || nums.length == 0) {
            return -1;
        }
        int left = 0;
        int right = nums.length - 1;
        int mid;
        while(left < right - 1) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[right] == target) {
                return right;
            }
            if(nums[left] == target) {
                return left;
            }
            else if(target > nums[mid]) {
                if(nums[mid] >= nums[0]) {
                    left = mid;
                }
                else {
                    if(target >= nums[0] && nums[nums.length - 1] < nums[0]) {
                        right = mid;
                    }
                    else {
                        left = mid;
                    }
                }
            }
            else {
                if(nums[mid] < nums[0]) {
                    right = mid;
                }
                else {

                    if(target <= nums[nums.length - 1] && nums[nums.length - 1] < nums[0]) {
                        left = mid;
                    }
                    else {
                        right = mid;
                    }
                }
            }

        }
        if(nums[right] == target) {
            return right;
        }
        if(nums[left] == target) {
            return left;
        }
        return  -1;
    }
}
