import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;

/***
 * 5mins brutal force
 * 54
 *
 *
 */
public class Q862_ShortestSubarrayWithSumAtLeastK {
    public int shortestSubarray(int[] A, int K) {
        int length = Integer.MAX_VALUE;
        for(int i = 0; i < A.length; i++) {
            int sum = 0;
            int l = 0;
            for(int j = i; j < A.length; j++) {
                sum += A[j];
                l++;
                if(sum >= K) {
                    length = Math.min(length, l);
                }
            }
        }
        return length == Integer.MAX_VALUE ? -1 : length;
    }

    public int shortestSubarray2(int[] A, int K) {
        TreeMap<Integer, Integer> sumMap = new TreeMap();
        int result = Integer.MAX_VALUE;
        int sum = 0;
        for(int i = 0; i < A.length; i++) {
            sum += A[i];
            SortedMap<Integer, Integer> tmp = sumMap.tailMap(sum - K, true);
            int idx = sumMap.getOrDefault(sum, 0);
            if(i > idx) {
                sumMap.put(sum, i);
            }
            if(tmp.size() == 0) {
                continue;
            }
            else {
                int max = Integer.MIN_VALUE;
                for(int m : tmp.values()) {
                    max = Math.max(max, m);
                }
                result = Math.min(result, i - max);
            }
        }
        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
