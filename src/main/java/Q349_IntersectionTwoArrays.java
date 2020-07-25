import java.util.Arrays;
import java.util.HashSet;

/***
 * 6mins easy
 * Runtime: 2 ms, faster than 99.28% of Java online submissions for Intersection of Two Arrays.
 * Memory Usage: 39.3 MB, less than 87.02% of Java online submissions for Intersection of Two Arrays.
 */
public class Q349_IntersectionTwoArrays {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> s = new HashSet();
        for(int i = 0; i < nums1.length; i++) {
            s.add(nums1[i]);
        }
        HashSet<Integer> r = new HashSet();
        for(int i = 0; i < nums2.length; i++) {
            if(s.contains(nums2[i])) {
                r.add(nums2[i]);
            }
        }
        int[] result = new int[r.size()];
        int i = 0;
        for(Integer x : r) {
            result[i++] = x;
        }
        return result;
    }
}
