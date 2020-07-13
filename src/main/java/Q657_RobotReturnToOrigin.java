/***
 * 3mins
 * Runtime: 5 ms, faster than 63.76% of Java online submissions for Robot Return to Origin.
 * Memory Usage: 39.3 MB, less than 78.78% of Java online submissions for Robot Return to Origin.
 */
public class Q657_RobotReturnToOrigin {
    public boolean judgeCircle(String moves) {
        int[] d = new int[2];
        for(int i = 0; i < moves.length(); i++) {
            char c = moves.charAt(i);
            switch(c) {
                case 'R':
                    d[0]++;
                    break;
                case 'L':
                    d[0]--;
                    break;
                case 'U':
                    d[1]++;
                    break;
                case 'D':
                    d[1]--;
                    break;
            }
        }
        return d[0] == 0 && d[1] == 0;
    }
}
