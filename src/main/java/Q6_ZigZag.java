/***
 * Runtime: 2 ms 99.87%
 * Memory Usage: 40 MB
 */

public class Q6_ZigZag {
    public String convert(String s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        StringBuilder sb = new StringBuilder();
        int iteration = numRows * 2 - 2;
        int counter = 0;
        while(counter < s.length()) {
            sb.append(s.charAt(counter));
            counter += iteration;
        }
        for(int i = 1; i < numRows - 1; i++) {
            counter = 0;
            while(i + counter < s.length()) {
                sb.append(s.charAt(i + counter));
                if(i + counter + (numRows - i - 1) * 2 >= s.length()) {
                    break;
                }
                sb.append(s.charAt(i + counter + (numRows - i - 1) * 2));
                counter += iteration;
            }
        }
        counter = numRows - 1;
        while(counter < s.length()) {
            sb.append(s.charAt(counter));
            counter += iteration;
        }
        return sb.toString();
    }
}
