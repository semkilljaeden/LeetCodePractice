import java.util.ArrayList;
import java.util.HashMap;

/***
 * 8mins
 * Runtime: 2 ms, faster than 98.80% of Java online submissions for Intersection of Two Arrays II.
 * Memory Usage: 39.3 MB, less than 88.73% of Java online submissions for Intersection of Two Arrays II.
 */
public class Q350_IntersectionTwoArraysII {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> s = new HashMap();
        for(int i = 0; i < nums1.length; i++) {
            int x = s.getOrDefault(nums1[i], 0);
            s.put(nums1[i], ++i);
        }
        ArrayList<Integer> a = new ArrayList();
        for(int i = 0; i < nums2.length; i++) {
            if(s.containsKey(nums2[i])) {
                a.add(nums2[i]);
                int x = s.get(nums2[i]);
                x--;
                if(x > 0) {
                    s.put(nums2[i], x);
                }
                else {
                    s.remove(nums2[i]);
                }
            }
        }
        int[] result = new int[a.size()];
        for(int i = 0; i < a.size(); i++) {
            result[i] = a.get(i);
        }
        return result;
    }
}
