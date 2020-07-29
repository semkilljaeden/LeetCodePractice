import java.util.Arrays;

/***
 * 1:30hr hard, fixing silly error
 * Runtime: 21 ms, faster than 82.86% of Java online submissions for Maximum Profit in Job Scheduling.
 * Memory Usage: 48.8 MB, less than 43.64% of Java online submissions for Maximum Profit in Job Scheduling.
 */
public class Q1235_MaximumProfitinJobScheduling {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int[][] t = new int[startTime.length][3];
        int[] ida = new int[t.length];
        for(int i = 0; i < startTime.length; i++) {
            ida[i] = startTime[i];
            t[i][0] = startTime[i];
            t[i][1] = endTime[i];
            t[i][2] = profit[i];
        }
        Arrays.sort(t, (o1, o2) -> {
            return o1[0] != o2[0] ? o1[0] - o2[0] : o1[1] - o2[1];
        });

        Arrays.sort(ida);
        for(int i = t.length - 2; i >= 0; i--) {
            int idx = Arrays.binarySearch(ida, t[i][1]);
            idx = idx > 0 ? idx : -idx - 1;
            if(idx < t.length) {
                t[i][2] += t[idx][2];
            }
            if(i + 1 < t.length) {
                t[i][2] = Math.max(t[i][2], t[i + 1][2]);
            }
            if(i + 1 < t.length) t[i][2] = Math.max(t[i][2], t[i + 1][2]);
        }
        return t[0][2];
    }
}
