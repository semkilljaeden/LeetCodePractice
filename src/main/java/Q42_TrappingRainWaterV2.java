/***
 * still out of time limit
 */

public class Q42_TrappingRainWaterV2 {
    public int trap(int[] height) {
        if(height == null || height.length == 0) {
            return 0;
        }
        int result = 0;
        boolean hasStarted;
        int tmpResult = 0;
        int left = 0;
        int right = height.length - 1;
        int tmpRight = 0;
        while(left < right) {
            hasStarted = false;
            tmpResult = 0;
            tmpRight = 0;
            for(int i = left; i <= right; i++) {
                if(height[i] > 0) {
                    height[i] -= 1;
                    tmpRight = i;
                    if(!hasStarted) {
                        hasStarted = true;
                        tmpResult = 0;
                        left = i;
                    }
                    else {
                        result += tmpResult;
                        tmpResult = 0;
                    }
                }
                else {
                    tmpResult += 1;
                }
            }
            right = tmpRight;
        }
        return result;
    }
}
