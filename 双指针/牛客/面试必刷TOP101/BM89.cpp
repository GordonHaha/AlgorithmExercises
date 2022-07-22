// https://www.nowcoder.com/practice/69f4e5b7ad284a478777cb2a17fb5e6a

#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval &a, Interval &b) {
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if(intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for(int i = 1;i < intervals.size();i++) {
            if(intervals[i].start <= res.back().end) {
                res.back().end = max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};