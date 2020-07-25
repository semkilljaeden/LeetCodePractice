/***
 * Runtime: 3 ms 100%
 * Memory Usage: 39.1 MB  98.68%
 */

class Q13_RomanToInt {
    public int romanToInt(String s) {
        int result = 0;
        int previous = convert(s.charAt(0));
        int tmp = 0;
        for(int i = 0; i < s.length(); i++) {
            int current = convert(s.charAt(i));
            if(current > previous) {
                result = result - tmp;
                tmp = 0;
                tmp += current;
            }
            else if(current < previous){
                result = result + tmp;
                tmp = 0;
                tmp += current;
            }
            else {
                tmp += current;
            }
            previous = current;
        }
        return result + tmp;
    }

    public int convert(char c) {
        switch (c) {
            case 'I': return             1;
            case 'V': return             5;
            case 'X': return             10;
            case 'L': return             50;
            case 'C': return             100;
            case 'D': return             500;
            case 'M': return             1000;
        }
        return Integer.MAX_VALUE * -1;
    }
}