import java.util.Arrays;

/**
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Merge Sorted Array.
 * Memory Usage: 39.3 MB, less than 86.34% of Java online submissions for Merge Sorted Array.
 * Next challenges:
 */
public class Q88_MergeSortedArrayV2 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if(nums1.length == 0 || nums2.length == 0) {
            return;
        }
        int j = n - 1;
        int k = m - 1;
        for(int i = m + n - 1; i >= 0; i--) {
            if(k >= 0 && j >= 0) {
                if(nums1[k] > nums2[j]) {
                    nums1[i] = nums1[k--];
                }
                else if(nums1[k] <= nums2[j]) {
                    nums1[i] = nums2[j--];
                }
            }
            else if(k < 0 && j < 0) { //remember! the boundary of no element is -1 or length!!!
                return;
            }
            else if(k < 0) {
                nums1[i] = nums2[j--];
            }
            else if(j < 0) {
                return;
            }

        }
    }
}
