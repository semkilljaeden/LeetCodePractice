#include "LCHeader.h"
#include "queue"
//7:11 7:28 hard, wonderful
/*
Runtime: 88 ms, faster than 99.27% of C++ online submissions for Find Median from Data Stream.
Memory Usage: 46.8 MB, less than 84.92% of C++ online submissions for Find Median from Data Stream.
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, std::greater<int>> _min;
    priority_queue<int, vector<int>, std::less<int>> _max;
    MedianFinder() {
        _min.push(INT_MAX);
        _max.push(INT_MIN);
    }

    void addNum(int num) {
        auto& min = _min.top();
        auto& max = _max.top();
        if (num <= min && num >= max) {
            _min.size() <= _max.size() ? _min.push(num) : _max.push(num);
        }
        else if (num > min) {
            _min.push(num);
            if (_min.size() - 2 == _max.size()) {
                _max.push(_min.top());
                _min.pop();
            }
        }
        else if (num < max) {
            _max.push(num);
            if (_max.size() - 2 == _min.size()) {
                _min.push(_max.top());
                _max.pop();
            }
        }
    }

    double findMedian() {
        return _min.size() == _max.size() ? ((double)_min.top() + (double)_max.top()) / 2.0 : _min.size() > _max.size() ? _min.top() : _max.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */