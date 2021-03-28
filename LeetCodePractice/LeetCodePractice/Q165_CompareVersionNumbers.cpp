#include<vector>
#include<string>
using namespace std;

//cleaner code


class Solution {
public:
    int compareVersion(string version1, string version2) {
        return c(version1, version2, 0, 0);
    }

    int c(const string& v1, const string& v2, int l, int r) {
        if (l == v1.size()) {
            for (; r < v2.size(); r++) {
                if (v2[r] != '.' && v2[r] != '0') {
                    return -1;
                }
            }
            return 0;
        }

        else if (r == v2.size()) {
            for (; l < v1.size(); l++) {
                if (v1[l] != '.' && v1[l] != '0') {
                    return 1;
                }
            }
            return 0;
        }
        if (v1[l] == '.') {
            l++;
        }
        if (v2[r] == '.') {
            r++;
        }
        int l2 = l;
        while (v1[l2] != '.' && l2 < v1.size()) {
            l2++;
        }
        int r2 = r;
        while (v2[r2] != '.' && r2 < v2.size()) {
            r2++;
        }
        int tmp = com(v1, v2, l, l2, r, r2);
        if (tmp != 0) {
            return tmp;
        }
        return c(v1, v2, l2, r2);
    }

    inline int com(const string& v1, const string& v2, int l, int l2, int r, int r2) {
        while (l < l2 && v1[l] == '0') {
            l++;
        }
        while (r < r2&& v2[r] == '0') {
            r++;
        }
        int lsize = l2 - l;
        int rsize = r2 - r;
        if (lsize != rsize) {
            return lsize > rsize ? 1 : -1;
        }

        while (l < l2 && r < r2) {
            if (v1[l] != v2[r]) {
                return v1[l] > v2[r] ? 1 : -1;
            }
            l++;
            r++;
        }
        return 0;
    }

};







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