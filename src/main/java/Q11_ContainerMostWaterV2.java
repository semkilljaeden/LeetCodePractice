/***
 * fast O(1)
 *
 * 1ms 99.99%
 *
 * slower O(n)
 *
 * 2ms 96%
 *
 */


public class Q11_ContainerMostWaterV2 {
    public int maxArea(int[] height) {
        int i = 0;
        int j = height.length - 1;
        int result = 0;
        while(i < j) {
            int tmp = (j - i) * (height[i] < height[j] ? height[i++] : height[j--]);
            if(result < tmp) {
                result = tmp;
            }
            /*** slower
             *             result = Math.max(result, (j - i) * Math.min(height[i], height[j]));
             *             if(height[i] > height[j]) {
             *                 j--;
             *             }
             *             else {
             *                 i++;
             *             }
             */
        }
        return result;
    }
}
