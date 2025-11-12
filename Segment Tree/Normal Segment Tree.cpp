/*
  Author: rudxkush
*/
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> seg, ar;
    int n;

    SegmentTree(vector<int>& nums) {
        ar = nums;
        n = (int)nums.size();
        seg.assign(4 * n, INT_MAX);
        build(0, 0, n - 1);
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = ar[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx + 1, l, mid);
        build(2 * idx + 2, mid + 1, r);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void pointUpdate(int i, int val) {
        int diff = val - ar[i];
        ar[i] = val;
        pointUpdateUtil(0, 0, n - 1, i, diff);
    }

    void pointUpdateUtil(int idx, int l, int r, int i, int diff) {
        if (i < l || i > r) return;
        if (l == r) {
            seg[idx] += diff;
            return;
        }
        int mid = (l + r) / 2;
        pointUpdateUtil(2 * idx + 1, l, mid, i, diff);
        pointUpdateUtil(2 * idx + 2, mid + 1, r, i, diff);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void rangeUpdate(int ql, int qr, int delta) {
        for (int i = ql; i <= qr; i++) ar[i] += delta;
        rangeUpdateUtil(0, 0, n - 1, ql, qr, delta);
    }

    void rangeUpdateUtil(int idx, int l, int r, int ql, int qr, int delta) {
        if (r < ql || l > qr) return;
        if (l == r) {
            seg[idx] += delta;
            return;
        }
        int mid = (l + r) / 2;
        rangeUpdateUtil(2 * idx + 1, l, mid, ql, qr, delta);
        rangeUpdateUtil(2 * idx + 2, mid + 1, r, ql, qr, delta);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int ql, int qr) {
        return queryUtil(0, 0, n - 1, ql, qr);
    }

    int queryUtil(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && qr >= r) return seg[idx];
        if (qr < l || ql > r) return INT_MAX;
        int mid = (l + r) / 2;
        return min(queryUtil(2 * idx + 1, l, mid, ql, qr),
                   queryUtil(2 * idx + 2, mid + 1, r, ql, qr));
    }
};
