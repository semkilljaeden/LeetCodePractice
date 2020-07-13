import java.util.Arrays;

/***
 * 1:36 3mins brutal force
 */
public class Q780_ReachingPoints {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx > tx || sy > ty) {
            return false;
        }
        if(sx == tx && sy == ty) {
            return true;
        }
        return reachingPoints(sx + sy, sy, tx, ty) || reachingPoints(sx, sy + sx, tx, ty);
    }

    public boolean reachingPoints2(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy) {
            if(tx > ty) {
                if(ty < sy) {
                    return false;
                }
                if(ty == sy) {
                    return (tx - sx) % sy == 0;
                }
                else {
                    tx %= ty;
                }
            }
            if(tx < sx) {
                return false;
            }
            if(tx == sx) {
                return (ty - sy) % sx == 0;
            }
            else {
                ty %= tx;
            }
        }
        return (tx == sx && ty == sy);
    }
}
