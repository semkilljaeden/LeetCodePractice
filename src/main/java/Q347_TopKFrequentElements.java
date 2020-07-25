import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/***
 * 30mins medium
 * Runtime: 7 ms, faster than 99.28% of Java online submissions for Top K Frequent Elements.
 * Memory Usage: 41.9 MB, less than 63.55% of Java online submissions for Top K Frequent Elements.
 */
public class Q347_TopKFrequentElements {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> count = new HashMap();
        for(int i = 0; i < nums.length; i++) {
            int x = count.getOrDefault(nums[i], 0);
            x++;
            count.put(nums[i], x);
        }
        ArrayList<Integer>[] bs = new ArrayList[nums.length + 1];
        for(Map.Entry<Integer, Integer> e : count.entrySet()) {
            int idx = e.getValue();
            if(bs[idx] == null) {
                bs[idx] = new ArrayList();
            }
            bs[idx].add(e.getKey());
        }
        int[] result = new int[k];
        int idx = 0;
        for(int i = bs.length - 1; i >= 0 ; i--) {
            if(bs[i] == null) {
                continue;
            }
            for(Integer x : bs[i]) {
                result[idx++] = x;
                if(idx >= k) {
                    return result;
                }
            }
        }
        return result;
    }
}
