/***
 * 4 ms  90.84%
 * 39.3 MB 60.52%
 */

class Solution {
    public String intToRoman(int num) {
        char[] result = new char[16];
        int tmp;
        Integer index = 15;
        int digit = 1;
        while(num > 0) {
            tmp = num % 10;
            if(tmp < 4) {
                index = populate(result, index, tmp, digit);
            }
            else if(tmp > 3 && tmp < 5) {
                result[index--] = getRoman(5, digit);
                index = populate(result, index, 5 - tmp, digit);
            }
            else if(tmp == 5) {
                result[index--] = getRoman(5, digit);
            }
            else if(tmp > 5 && tmp < 9) {
                index = populate(result, index, tmp - 5, digit);
                result[index--] = getRoman(5, digit);
            }
            else if(tmp > 7 && tmp < 10) {
                result[index--] = getRoman(1, digit + 1);
                index = populate(result, index, 10 - tmp, digit);
            }
            else {
                result[index--] = getRoman(1, digit + 1);
            }
            digit++;
            num /= 10;
        }
        return new String(result).trim();

    }

    public int populate(char[] result, int index, int i, int digit) {
        while(i-- > 0) {
            result[index--] = getRoman(1, digit);
        }
        return index;
    }

    public char getRoman(int i, int digit) {
        if(i == 1) {
            switch(digit) {
                case 1:
                    return 'I';
                case 2:
                    return 'X';
                case 3:
                    return 'C';
                case 4:
                    return 'M';
            }
        }
        if(i == 5) {
            switch (digit) {
                case 1:
                    return 'V';
                case 2:
                    return 'L';
                case 3:
                    return 'D';
            }
        }
        return 'A';
    }
}