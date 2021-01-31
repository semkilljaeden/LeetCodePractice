#include<vector>
#include<string>
using namespace std;
//4:56 5:40 too slow, unfamiliar with c++ string
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Compare Version Numbers.
Memory Usage: 6.1 MB, less than 88.43% of C++ online submissions for Compare Version Numbers.
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0;
        int p2 = 0;
        int pe1 = version1.find(".", p1);
        int pe2 = version2.find(".", p2);
        vector<int> pv1;
        vector<int> pv2;
        while (pe1 != string::npos)
        {
            int t1 = stoi(version1.substr(p1, pe1 - p1));
            pv1.push_back(t1);
            p1 = pe1 + 1;
            pe1 = version1.find(".", p1);
        }
        while (pe2 != string::npos)
        {
            int t2 = stoi(version2.substr(p2, pe2 - p2));
            pv2.push_back(t2);
            p2 = pe2 + 1;
            pe2 = version2.find(".", p2);
        }
        if (p1 < version1.size())
        {
            pv1.push_back(stoi(version1.substr(p1, version1.size() - p1)));
        }
        if (p2 < version2.size())
        {
            pv2.push_back(stoi(version2.substr(p2, version2.size() - p2)));
        }
        auto itr1 = pv1.cbegin();
        auto itr2 = pv2.cbegin();
        while (itr1 != pv1.cend() && itr2 != pv2.cend())
        {
            if (*itr1 < *itr2)
            {
                return -1;
            }
            if (*itr1 > *itr2)
            {
                return 1;
            }
            itr1++;
            itr2++;
        }
        if (itr1 == pv1.cend() && itr2 == pv2.cend())
        {
            return 0;
        }
        auto itr = itr1 != pv1.cend() ? itr1 : itr2;
        auto& v = itr1 != pv1.cend() ? pv1 : pv2;
        int r = itr1 != pv1.cend() ? 1 : -1;
        while (itr != v.cend())
        {
            if (*itr != 0)
            {
                return r;
            }
            itr++;
        }
        return 0;
    }
};