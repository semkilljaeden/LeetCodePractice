/***
 * still out of time limit
 */

public class Q42_TrappingRainWaterDP {
    public int trap(int[] height) {
        if(height == null || height.length == 0) {
            return 0;
        }
        int[] leftMax = new int[height.length];
        int[] rightMax = new int[height.length];
        leftMax[0] = height[0];
        rightMax[height.length - 1] = height[height.length - 1];
        for(int i = 1; i < height.length; i++) {
            if(height[i] > leftMax[i - 1]) {
                leftMax[i] = height[i];
            }
            else {
                leftMax[i] = leftMax[i - 1];
            }
        }
        for(int i = height.length - 2; i >= 0; i--) {
            if(height[i] > rightMax[i + 1]) {
                rightMax[i] = height[i];
            }
            else {
                rightMax[i] = rightMax[i + 1];
            }
        }
        int result = 0;
        for(int i = 0; i < height.length; i++) {
            int h = Math.min(leftMax[i], rightMax[i]);
            if(h > height[i]) {
                result += h - height[i];
            }
        }
        return result;
    }
}
