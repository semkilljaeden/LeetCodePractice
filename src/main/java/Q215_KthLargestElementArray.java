/***
 * 36mins. got the question the other way around, was thinking about kth element rather than kth large
 * should be logn, why so slow？
 * Runtime: 17 ms, faster than 16.22% of Java online submissions for Kth Largest Element in an Array.
 * Memory Usage: 40.6 MB, less than 25.06% of Java online submissions for Kth Largest Element in an Array.
 */
public class Q215_KthLargestElementArray {
    int[] nums;
    int k;
    int result;
    public int findKthLargest(int[] nums, int k) {
        this.nums = nums;
        this.k = k;
        qSort(0, nums.length - 1);
        return result;
    }


    public void qSort(int i, int j) {
        if(i >= j) {
            if(i == nums.length - k) {
                result = nums[i];
            }
            return;
        }
        int start = i + 1;
        int end = j;
        while(start < end) {
            if(nums[start] < nums[i]) {
                start++;
            }
            else if(nums[end] >= nums[i]) {
                end--;
            }
            else if(nums[end] < nums[i] && nums[start] >= nums[i]) {
                swap(start, end);
                start++;
                end--;
            }
        }
        start = start <= end ? start : end;
        end = end > start ? end : start;
        int pivot;
        if(nums[start] >= nums[i]) {
            pivot = start - 1;
        }
        else {
            pivot = start;

        }
        if(pivot == nums.length - k) {
            result = nums[i];
            return;
        }
        swap(i, pivot);
        if(pivot > nums.length - k) {
            qSort(i, pivot - 1);
        }
        else {
            qSort(pivot + 1, j);
        }
    }

    public void swap(int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
