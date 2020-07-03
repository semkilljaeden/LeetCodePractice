import java.util.LinkedList;
import java.util.Stack;

/**
 * Read the answer.
 *
 * Runtime: 5 ms, faster than 90.49% of Java online submissions for Largest Rectangle in Histogram.
 * Memory Usage: 40.3 MB, less than 93.60% of Java online submissions for Largest Rectangle in Histogram.
 */
public class Q84_LargestRectangleInHistogramV2 {
    public int largestRectangleArea(int[] heights) {
        LinkedList<Integer> s = new LinkedList<Integer>();
        int result = 0;
        for(int i = 0; i < heights.length; i++) {
            while(s.size() > 0 && heights[s.getLast()] > heights[i]) {
                result = Math.max(result, heights[s.removeLast()] * (i - (s.size() == 0 ? 0 : s.getLast() + 1)));
            }
            s.addLast(i);
        }
        while(s.size() > 0) {
            result = Math.max(result, heights[s.removeLast()] * (heights.length - (s.size() == 0 ? 0 : s.getLast() + 1)));
        }
        return result;
    }
}
