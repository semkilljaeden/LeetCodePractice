#include<vector>
#include<queue>
using namespace std;
//took like 3 hours, finally get it correct

class Solution {
public:
    using vp = vector<int>;
    vector<vp> getSkyline(vector<vector<int>>& buildings) {
        return dc(buildings, 0, buildings.size());
    }
    vector<vp> dc(const vector<vector<int>>& b, int i, int j) {
        if (i + 1 == j) {
            return vector<vp>{vp{ b[i][0], b[i][2] }, vp{ b[i][1], 0 }};
        }
        if (i == j) {
            return vector<vp>();
        }
        auto left = dc(b, i, (j - i) / 2 + i);
        auto right = dc(b, (j - i) / 2 + i, j);
        return merge(left, right);
    }
    vector<vp> merge(const vector<vp>& left, const vector<vp>& right) {
        vector<vp> result;
        if (left.size() == 0 && right.size() == 0) {
            return result;
        }
        else if (left.size() == 0) {
            result = right;
            return result;
        }
        else if (right.size() == 0) {
            result = left;
            return result;
        }
        int i = 0;
        int j = 0;
        int rh = 0;
        int lh = 0;
        int ch = 0;
        bool cur = true;
        while (i < left.size() && j < right.size()) {
            auto& l = left[i];
            auto& r = right[j];
            int tmp = ch;
            if (l[0] == r[0]) {
                tmp = max(lh = l[1], rh = r[1]);
                if (tmp != ch) {
                    result.emplace_back(vp{ l[0], ch = tmp });
                }

                i++;
                j++;
            }
            else if (l[0] < r[0]) {
                if (lh == ch) {
                    tmp = l[1] < rh ? rh : l[1];
                }
                else if (lh != ch && l[1] > ch) {
                    tmp = l[1];
                }
                if (tmp != ch) {
                    result.emplace_back(vp{ l[0], ch = tmp });
                }
                lh = l[1];
                i++;
            }
            else if (l[0] > r[0]) {
                if (rh == ch) {
                    tmp = r[1] < lh ? lh : r[1];
                }
                else if (rh != ch && r[1] > ch) {
                    tmp = r[1];
                }
                if (tmp != ch) {
                    result.emplace_back(vp{ r[0], ch = tmp });
                }
                rh = r[1];
                j++;
            }
        }
        while (i < left.size()) {
            if (left[i][1] != ch) {
                result.emplace_back(vp{ left[i][0], ch = left[i][1] });
            }
            i++;
        }
        while (j < right.size()) {
            if (right[j][1] != ch) {
                result.emplace_back(vp{ right[j][0], ch = right[j][1] });
            }
            j++;
        }
        return result;
    }
};

//10:37 to 11:37, weird bug failed. this approach is too complex

class Solution2 {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.size() == 0)
        {
            return vector<vector<int>>();
        }
        using vp = vector<int>;
        auto max = [](vp* v1, vp* v2) {return (*v1)[2] < (*v2)[2]; };
        priority_queue<vp*, vector<vp*>, decltype(max)> h(max);
        vector<vector<int>> result;
        int height = buildings[0][2];
        int end = buildings[0][1];
        int start = buildings[0][0];
        auto c = &buildings[0];
        result.push_back(vp{ buildings[0][0], buildings[0][2] });
        int count = 1;
        while (count < buildings.size()) {
            auto& b = buildings[count];
            if (b[0] == start && b[2] > height) {
                result.pop_back();
            }
            if (b[0] <= end)
            {
                if (b[2] <= height && b[1] > end)
                {
                    h.push(&b);
                }
                else if (b[2] > height) {
                    result.push_back(vp{ b[0], b[2] });
                    if (b[1] < end) {
                        h.push(c);
                    }
                    height = b[2];
                    end = b[1];
                    start = b[0];
                    c = &b;
                }
                count++;
                continue;
            }
            while (h.size() != 0) {
                auto x = h.top();
                auto& xx = *x;
                h.pop();
                if (xx[1] <= end) {
                    continue;
                }
                if (xx[2] < height)
                {
                    result.push_back(vp{ end, xx[2] });
                }
                height = xx[2];
                end = xx[1];
                start = xx[0];
                c = x;
            }
            if (b[0] > end) {
                result.push_back(vp{ end, 0 });
            }
            if (b[0] == end && b[2] > height || b[0] > end) {
                result.push_back(vp{ b[0], b[2] });
            }
            height = b[2];
            end = b[1];
            start = b[0];
            c = &b;
            count++;
        }
        while (h.size() != 0) {
            auto x = h.top();
            auto& xx = *x;
            h.pop();
            if (xx[1] <= end) {
                continue;
            }
            if (xx[2] < height)
            {
                result.push_back(vp{ end, xx[2] });
            }
            height = xx[2];
            end = xx[1];
            start = xx[0];
            c = x;
        }
        result.push_back(vp{ end, 0 });
        return result;
    }
};