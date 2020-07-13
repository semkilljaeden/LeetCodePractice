/***
 * 18mins medium one shot AC
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Game of Life.
 * Memory Usage: 39.7 MB, less than 5.07% of Java online submissions for Game of Life.
 */
public class Q289_GameOfLife {
    public void gameOfLife(int[][] nums) {
        if(nums.length == 0) {
            return;
        }
        for(int i = 0; i < nums.length; i++) {
            for(int j = 0; j < nums[0].length; j++) {
                int lv = 0;
                lv += i - 1 >= 0 && Math.abs(nums[i - 1][j]) == 1 ? 1 : 0;
                lv += i + 1 < nums.length && Math.abs(nums[i + 1][j]) == 1 ? 1 : 0;
                lv += j - 1 >= 0 && Math.abs(nums[i][j - 1]) == 1 ? 1 : 0;
                lv += j + 1 < nums[0].length && Math.abs(nums[i][j + 1]) == 1 ? 1 : 0;
                lv += i - 1 >= 0 && j - 1 >= 0 && Math.abs(nums[i - 1][j - 1]) == 1 ? 1 : 0;
                lv += i - 1 >= 0 && j + 1 < nums[0].length && Math.abs(nums[i - 1][j + 1]) == 1 ? 1 : 0;
                lv += i + 1 < nums.length && j - 1 >= 0 && Math.abs(nums[i + 1][j - 1]) == 1 ? 1 : 0;
                lv += i + 1 < nums.length && j + 1 < nums[0].length && Math.abs(nums[i + 1][j + 1]) == 1 ? 1 : 0;
                if(nums[i][j] == 1) {
                    if(lv < 2 || lv > 3) {
                        nums[i][j] = -1;
                    }
                }
                else {
                    if(lv == 3) {
                        nums[i][j] = -2;
                    }
                }
            }
        }

        for(int i = 0; i < nums.length; i++) {
            for(int j = 0; j < nums[0].length; j++) {
                if(nums[i][j] == -1) {
                    nums[i][j] = 0;
                }
                else if(nums[i][j] == -2) {
                    nums[i][j] = 1;
                }
            }
        }
    }
}
