import java.util.ArrayList;

/***
 * 2hr too slow
 * Runtime: 1 ms, faster than 99.01% of Java online submissions for Insert Interval.
 * Memory Usage: 42 MB, less than 28.38% of Java online submissions for Insert Interval.
 *
 * no need to do case by case, greedy is easier
 */
public class Q57_InsertIntervalV2 {
    ArrayList<int[]> result = new ArrayList();
    int[][] intervals;
    public int[][] insert(int[][] intervals, int[] newInterval) {
        this.intervals = intervals;
        if(intervals.length == 0) {
            return new int[][] {newInterval};
        }
        int i = 0;
        while(i < intervals.length && intervals[i][1] < newInterval[0]) {
            result.add(intervals[i]);
            i++;
        }
        //case
        while(i < intervals.length && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.add(newInterval);
        while(i < intervals.length) {
            result.add(intervals[i]);
            i++;
        }
        return result.toArray(new int[result.size()][]);

    }

}
