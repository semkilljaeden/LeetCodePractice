/**
 * 26mins dummy O(n^2)
 * Runtime: 992 ms, faster than 5.01% of Java online submissions for Largest Rectangle in Histogram.
 * Memory Usage: 44.2 MB, less than 17.93% of Java online submissions for Largest Rectangle in Histogram.
 */
public class Q84_LargestRectangleInHistogram {
    public int largestRectangleArea(int[] heights) {
        int result = 0;
        for(int i = 0; i < heights.length; i++) {
            int h = 0;
            int height = heights[i];
            for(int j = i; j >= 0; j--) {
                if(heights[j] < height) {
                    break;

                }
                h += height;
            }
            for(int j = i + 1; j < heights.length; j++) {
                if(heights[j] < height) {
                    break;

                }
                h += height;
            }
            result = Math.max(result, h);
        }
        return result;
    }
}
