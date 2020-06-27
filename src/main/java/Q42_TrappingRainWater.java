/***
 * 30mins hard out of time limit
 */

public class Q42_TrappingRainWater {
    public int trap(int[] height) {
        if(height == null || height.length == 0) {
            return 0;
        }
        int result = 0;
        boolean hasStarted = false;
        int tmpResult = 0;
        int count = 0;
        while(true) {
            hasStarted = false;
            count = 0;
            tmpResult = 0;
            for(int i = 0; i < height.length; i++) {
                if(height[i] > 0) {
                    height[i] -= 1;
                    count++;
                    if(!hasStarted) {
                        hasStarted = true;
                        tmpResult = 0;
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


            if(count < 2) {
                break;
            }
        }
        return result;
    }
}
