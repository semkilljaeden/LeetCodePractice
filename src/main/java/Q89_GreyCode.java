import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 30mins medium,
 * not AC, but it works, test cases issue
 *
 * no!!! this does not work!!!!!
 * damn!!
 * total wrong answer
 *  
 */
@Deprecated
public class Q89_GreyCode {

    public List<Integer> grayCode(int n) {
        int count = 1 << n;
        int r = 0;
        List<Integer> result = new ArrayList();
        result.add(0);
        if(--count == 0) {
            return result;
        }
        int layer = 0;
        while(true) {
            r += 1 << (0 + layer);
            result.add(r);
            if(--count == 0) {
                return result;
            }
            if(layer - 1 >= 0) {
                r -= 1 <<(0 + layer - 1);
                result.add(r);
                if(--count == 0) {
                    return result;
                }
            }
            layer++;
            layer %= n;
        }
    }
}
