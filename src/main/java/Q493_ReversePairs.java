import java.util.TreeMap;

/***
 * 16:22
 */
public class Q493_ReversePairs {
    public int reversePairs(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        TreeMap<Long, Integer> t = new TreeMap<>();
        int result = 0;
        for(int i = 0; i < nums.length; i++) {
            result += t.getOrDefault(t.headMap(nums[i] * 2L + 1).firstKey(), 0);
            t.put((long)nums[i],
                    t.getOrDefault(t.
                            tailMap((long)nums[i]).firstKey(), 0) + 1);
        }
        return result;
    }
}
