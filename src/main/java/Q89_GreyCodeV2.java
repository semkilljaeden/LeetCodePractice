import java.util.ArrayList;
import java.util.List;


public class Q89_GreyCodeV2 {
    public List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList();
        result.add(0);
        if(n == 0){
            return result;
        }
        result.add(1);
        int layer = 1;
        while(layer <= n - 1) {
            int size = result.size();
            for(int i = size - 1; i >= 0; i--) {
                result.add(result.get(i) + (1 << layer));
            }
            layer++;
        }
        return result;
    }
}
