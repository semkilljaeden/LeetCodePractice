import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/***
 *
 * 1hr medium
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Spiral Matrix.
 * Memory Usage: 37 MB, less than 97.68% of Java online submissions for Spiral Matrix.
 */
public class Q54_SpiralMatrix {
    public List<Integer> spiralOrder(int[][] matrix) {
        //boundary check
        List<Integer> result = new ArrayList<Integer>();
        if(matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0)         {
            return result;
        }
        int layer = 0;
        int i = layer;
        int j = layer;
        int vBoundary = matrix.length;
        int hBoundary = matrix[0].length;
        while(layer <= vBoundary && layer <= hBoundary) {
            do{
                if(i < layer || i >= vBoundary || j < layer || j >= hBoundary) {
                    break;
                }
                result.add(matrix[i][j]);
                if(i == layer) {
                    if(j < hBoundary - 1) {
                        j++;
                    }
                    else {
                        i++;
                    }
                }
                else if(i > layer && i < vBoundary - 1) {
                    if(j == layer && hBoundary - layer > 1) {
                        i--;
                    }
                    else {
                        i++;
                    }
                }
                else if(i == vBoundary - 1){
                    if(j > layer) {
                        j--;
                    }
                    else if(j == layer && hBoundary - layer > 1) {
                        i--;
                    }
                    else if(hBoundary - layer == 1){
                        i++; //to break out of boundary
                    }
                }

            }while(i != layer || j != layer);
            layer++;
            vBoundary--;
            hBoundary--;
            i = layer;
            j = layer;
        }
        return result;
    }
}
