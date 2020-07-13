import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/***
 * 23mins hashmap, 10mins brutal force
 * Runtime: 24 ms, faster than 42.86% of Java online submissions for Subarray Sum Equals K.
 * Memory Usage: 44.4 MB, less than 18.78% of Java online submissions for Subarray Sum Equals K.
 */
public class Q560_SubarraySumEqualsK {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        HashMap<Integer, List<Integer>> map = new HashMap();
        map.putIfAbsent(count, new ArrayList());
        map.get(0).add(-1);
        for(int i = 0; i < nums.length; i++) {
            count += nums[i];
            map.putIfAbsent(count, new ArrayList());
            map.get(count).add(i);
        }
        count = 0;
        for(int key : map.keySet()) {
            List<Integer> l = map.getOrDefault(key - k, new ArrayList<>(0));
            List<Integer> r = map.get(key);
            for(int i = 0; i < l.size(); i++) {
                for(int j = 0; j < r.size(); j++) {
                    if(l.get(i) < r.get(j)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }


    public int subarraySum2(int[] nums, int k) {
        int count = 0;
        for(int i = 0; i < nums.length; i++) {
            int sum = 0;
            for(int j = i; j < nums.length; j++) {
                sum += nums[j];
                if(sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
}
