/***
 * O(n^2)
 * 597 ms  5.62%
 * 39.8 MB 60.30%
 */


public class Q11_ContainerMostWater {
    public int maxArea(int[] height) {
        int result = 0;
        for(int i = 0; i < height.length - 1; i++) {
            for(int j = i + 1; j < height.length; j++) {
                int size = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
                if(result < size) {
                    result = size;
                }
            }
        }
        return result;
    }
}
