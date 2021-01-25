#include<vector>
using namespace std;
//4:43 to 6:10, TOP DOWN N^2 solution...... too weak TLE
//read the solution
class Solution2 {
public:
    int candy(vector<int>& c) {
        vector<int> ltr(c.size(), 1);
        vector<int> rtl(c.size(), 1);
        for (int i = 1; i < c.size(); i++)
        {
            if (c[i] > c[i - 1])
            {
                ltr[i] = ltr[i - 1] + 1;
            }
        }
        for (int i = c.size() - 2; i >= 0; i--)
        {
            if (c[i] > c[i + 1])
            {
                rtl[i] = rtl[i + 1] + 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < c.size(); i++)
        {
            sum += max(ltr[i], rtl[i]);
        }
        return sum;
    }
};







class Solution {
public:
    int candy(vector<int>& c) {
        int changed = c.size();
        vector<int> r(c.begin(), c.end());
        for (int& x : r)
        {
            x += 1;
        }
        while (changed > 0)
        {
            changed = c.size();
            for (size_t i = 0; i < c.size(); i++)
            {
                int left = i - 1 < 0 ? 0 : c[i - 1];
                int right = i + 1 >= c.size() ? 0 : c[i + 1];
                int leftv = i - 1 < 0 ? 0 : r[i - 1];
                int rightv = i + 1 >= c.size() ? 0 : r[i + 1];
                if (c[i] < left && c[i] < right)
                {
                    r[i] = 1;
                }
                else if (c[i] > left && c[i] > right)
                {
                    r[i] = (leftv > rightv ? leftv : rightv) + 1;
                }
                else if (c[i] > left && c[i] < right)
                {
                    r[i] = leftv + 1;
                }
                else if (c[i] < left && c[i] > right)
                {
                    r[i] = rightv + 1;
                }
                //equal
                else if (c[i] == left && c[i] == right)
                {
                    r[i] = 1;
                }
                else if (c[i] == left && c[i] > right)
                {
                    r[i] = rightv + 1;
                }
                else if (c[i] == left && c[i] < right)
                {
                    r[i] = 1;
                }
                else if (c[i] == right && c[i] > left)
                {
                    r[i] = left + 1;
                }
                else if (c[i] == right && c[i] < left)
                {
                    r[i] = 1;
                }
                else
                {
                    changed--;
                }
            }
        }
        int re = 0;
        for (int& x : r)
        {
            re += x;
        }
        return re;
    }
};
