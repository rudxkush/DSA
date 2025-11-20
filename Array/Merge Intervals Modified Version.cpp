/*
  Author : rudxkush
*/

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), 
    [](Interval a, Interval b) {
        return (a.start < b.start);
    });
    
    for(auto it : intervals) {
        // ex : [3,5], [4,9], [6, 7]
        if(res.empty() || res.back().end < it.start) {
            res.push_back(it);
        } else {
            res.back().end = max(res.back().end, it.end);   
        }
    }
    return res;
}
