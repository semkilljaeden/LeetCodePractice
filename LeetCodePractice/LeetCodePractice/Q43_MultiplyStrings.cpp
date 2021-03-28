#include "LCHeader.h"
//9:11 9:30

class Solution {//9:11
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string result;
        string zero;
        for (int i = num2.size() - 1; i >= 0; i--) {
            string tmp;
            int carry = 0;
            for (int j = num1.size() - 1; j >= 0; j--) {
                auto a = num1[j] - '0';
                auto b = num2[i] - '0';
                int x = a * b + carry;
                tmp += to_string(x % 10);
                carry = x / 10;
            }
            if (carry > 0) {
                tmp += to_string(carry);
            }
            reverse(tmp.begin(), tmp.end());
            tmp += zero;
            zero += '0';
            result = sum(result, tmp);
        }
        return result;
    }

    string sum(string& left, string right) {
        int i = left.size() - 1;
        int j = right.size() - 1;
        string result;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            auto a = left[i] - '0';
            auto b = right[j] - '0';
            int x = a + b + carry;
            result += to_string(x % 10);
            carry = x / 10;
            i--;
            j--;
        }
        if (i >= 0) {
            while (i >= 0) {
                auto a = left[i] - '0';
                int x = a + carry;
                result += to_string(x % 10);
                carry = x / 10;
                i--;
            }
        }
        else if (j >= 0) {
            while (j >= 0) {
                auto a = right[j] - '0';
                int x = a + carry;
                result += to_string(x % 10);
                carry = x / 10;
                j--;
            }
        }
        if (carry > 0) {
            result += to_string(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};