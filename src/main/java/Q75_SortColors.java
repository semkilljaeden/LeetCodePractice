import java.util.Arrays;

/***
 * 23mins
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Sort Colors.
 * Memory Usage: 37.6 MB, less than 95.94% of Java online submissions for Sort Colors.
 * Next challenges:
 */
public class Q75_SortColors {
    int[] nums;
    public void sortColors(int[] nums) {
        this.nums = nums;
        qSort(0, nums.length - 1);
    }

    public void qSort(int left, int right) {
        if(left >= right) {
            return;
        }
        int i = left + 1;
        int j = right;
        int pivot = nums[left];
        while(i < j) {
            if(nums[i] >= pivot) {
                if(nums[j] < pivot) {
                    swap(i++, j--);
                }
                else {
                    j--;
                }
            }
            else {
                i++;
            }

        }
        int pIndex = Math.min(i, j);
        if(nums[pIndex] >= pivot) {
            pIndex--;
        }
        swap(left, pIndex);
        qSort(left, pIndex);
        qSort(pIndex + 1, right);
    }

    public void swap(int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
