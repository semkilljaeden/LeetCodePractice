import java.util.Arrays;

/***
 * 6mins
 * Runtime: 1 ms, faster than 90.73% of Java online submissions for Height Checker.
 * Memory Usage: 37.2 MB, less than 74.71% of Java online submissions for Height Checker.
 */
public class Q1051_HeightChecker {
    public int heightChecker(int[] heights) {
        int[] tmp = Arrays.copyOf(heights, heights.length);
        int count = 0;
        Arrays.sort(tmp);
        for(int i = 0; i < tmp.length; i++) {
            if(tmp[i] != heights[i]) {
                count++;
            }
        }
        return count;
    }
}
