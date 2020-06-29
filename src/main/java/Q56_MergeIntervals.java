import java.util.ArrayList;
import java.util.Arrays;

/***
 * 25mins medium
 * Runtime: 5 ms, faster than 96.00% of Java online submissions for Merge Intervals.
 * Memory Usage: 42.2 MB, less than 45.72% of Java online submissions for Merge Intervals.
 */
public class Q56_MergeIntervals {
    public int[][] merge(int[][] intervals) {
        ArrayList<int[]> result = new ArrayList();
        Arrays.sort(intervals, ((o1, o2) -> {
            if(o1.length == 0) {
                return -1;
            }
            if(o2.length == 0) {
                return -1;
            }
            return o1[0] - o2[0];
        } ));
        int i = 0;
        while(i < intervals.length && intervals[i].length == 0) {
            i++;
        }
        if(i == intervals.length) {
            return new int[0][];
        }
        result.add(intervals[i]);
        for(i = i + 1; i < intervals.length; i++) {
            int[] prev = result.get(result.size() - 1);
            if(intervals[i][0] > prev[1]) {
                result.add(intervals[i]);
            }
            else if(intervals[i][0] >= prev[0] && intervals[i][0] < prev[1]) {
                if(intervals[i][1] <= prev[1]) {
                    continue;
                }
                else {
                    prev[1] = intervals[i][1];
                }
            }
            else if(intervals[i][0] == prev[1] && intervals[i][1] > prev[1]) {
                prev[1] = intervals[i][1];
            }
            else if(intervals[i][0] < prev[0]){
                //cannot happen
                continue;
            }
        }
        return result.toArray(new int[result.size()][]);
    }
}
