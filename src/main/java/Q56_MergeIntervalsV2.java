import java.util.ArrayList;
import java.util.Arrays;

/***
 * 25mins medium
 * Runtime: 5 ms, faster than 96.00% of Java online submissions for Merge Intervals.
 * Memory Usage: 42.2 MB, less than 45.72% of Java online submissions for Merge Intervals.
 */
public class Q56_MergeIntervalsV2 {
    public int[][] merge(int[][] intervals) {
        if(intervals.length == 0 || intervals[0].length == 0) {
            return new int[0][0];
        }
        Arrays.sort(intervals, (o1, o2) -> {
            return o1[0] == o2[0] ? o1[1] - o2[1] : o1[0] - o2[0];
        });

        ArrayList<int[]> result = new ArrayList();
        result.add(intervals[0]);
        for(int i = 1; i < intervals.length; i++) {
            int[] prev = result.get(result.size() - 1);
            int[] curr = intervals[i];
            if(curr[0] >= prev[0] && curr[0] <= prev[1]) {
                if(curr[1] > prev[1]) {
                    prev[1] = curr[1];
                }
            }
            else {
                result.add(curr);
            }
        }
        int[][] r = new int[result.size()][];
        for(int i = 0; i < r.length; i++) {
            r[i] = result.get(i);
        }
        return r;
    }
}
