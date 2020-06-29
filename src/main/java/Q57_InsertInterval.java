import java.util.ArrayList;

/***
 * 2hr too slow
 * Runtime: 1 ms, faster than 99.01% of Java online submissions for Insert Interval.
 * Memory Usage: 42 MB, less than 28.38% of Java online submissions for Insert Interval.
 *
 * logic can be much simplified by seperating the code into three part, adding normal bofore merging case,
 * add merging case, then add normal after merging case.
 */
public class Q57_InsertInterval {
    ArrayList<int[]> result = new ArrayList();
    int[][] intervals;
    public int[][] insert(int[][] intervals, int[] newInterval) {
        this.intervals = intervals;
        boolean added = false;
        if(intervals.length == 0) {
            return new int[][] {newInterval};
        }
        int prevBound = Integer.MIN_VALUE;
        for(int i = 0; i < intervals.length;) {
            int[] curr = intervals[i];
            if(curr.length == 0) {
                result.add(curr);
                i++;
                continue;
            }
            if(newInterval[0] <= curr[0]
                    && newInterval[0] > prevBound
                    && newInterval[1] <= curr[1]
                    && newInterval[1] >= curr[0]) {
                newInterval[1] = curr[1];
                result.add(newInterval);
                i++;
            }
            else if(newInterval[0] < curr[0]
                    && newInterval[0] > prevBound
                    && newInterval[1] > curr[1]) {
                result.add(newInterval);
                i = merge(i, newInterval);
            }
            else if(newInterval[0] >= curr[0]
                    && newInterval[0] <= curr[1]
                    && newInterval[1] <= curr[1]) {
                result.add(curr);
                i++;
            }
            else if(newInterval[0] >= curr[0]
                    && newInterval[0] <= curr[1]
                    && newInterval[1] > curr[1]) {
                result.add(curr);
                i = merge(i, newInterval);
            }
            else if(newInterval[0] > prevBound
                    && newInterval[1] < curr[0]){
                result.add(newInterval);
                result.add(curr);
                i++;
            }
            else if((i + 1 > intervals.length - 1 || newInterval[1] < intervals[i + 1][0])
                    && curr[1] < newInterval[0]) {
                result.add(curr);
                result.add(newInterval);
                i++;
            }
            else {
                result.add(curr);
                i++;
            }
            prevBound = result.get(result.size() - 1)[1];

        }
        return result.toArray(new int[result.size()][]);
    }

    public int merge(int i, int[] m) {
        while(i < intervals.length && intervals[i][0] <= m[1]) {
            i++;
        }
        int[] end = intervals[i - 1];
        result.get(result.size() - 1)[1] = end[1] > m[1] ? end[1] : m[1];
        return i;
    }
}
