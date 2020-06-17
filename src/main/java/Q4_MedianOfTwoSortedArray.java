/***
 * Runtime: 3 ms  40.8%
 * Memory Usage: 40.4 MB
 */

public class Q4_MedianOfTwoSortedArray {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int iMin = -1;
        int iMax = nums1.length + 1;
        int size1 = nums1.length;
        int size2 = nums2.length;
        int i = (iMax + iMin) / 2;
        int j = (int)Math.ceil((size1 + size2) / 2.0) - (i + 1) - 1;
        while(get(nums1, i) > get(nums2, j + 1) || get(nums2, j) > get(nums1, i + 1)) {
            if(get(nums1, i) > get(nums2, j + 1)) {
                iMax = i;
            }
            if(get(nums2, j) > get(nums1, i + 1)) {
                iMin = i + 1;
            }
            i = iMin + (iMax - iMin - 1) / 2;
            j = (int)Math.ceil((size1 + size2) / 2.0) - (i + 1) - 1;
        }
        double result = get(nums1, i) >  get(nums2, j) ?  get(nums1, i) :  get(nums2, j);
        if((size1 + size2) % 2 == 0) {
            double upper =  get(nums1, i + 1)  <  get(nums2, j + 1) ?  get(nums1, i + 1) :  get(nums2, j + 1);
            result = result + (upper - result) / 2.0;
        }
        return result;
    }

    private int get(int[] array, int index) {
        if(index < 0) {
            return Integer.MIN_VALUE;
        }
        if(index >= array.length) {
            return Integer.MAX_VALUE;
        }
        return array[index];
    }
}
