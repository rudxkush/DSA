/*
  Author : rudxkush
*/
#include <bits/stdc++.h>
using namespace std;

class LazySegmentTree {
public:
    vector<int> seg, lazy, ar;
    int n;

    LazySegmentTree(vector<int>& nums) {
        ar = nums;
        n = (int)nums.size();
        seg.assign(4 * n, INT_MAX);
        lazy.assign(4 * n, 0);
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

    void rangeUpdate(int ql, int qr, int delta) {
        rangeUpdateUtil(0, 0, n - 1, ql, qr, delta);
    }

    void rangeUpdateUtil(int idx, int l, int r, int ql, int qr, int delta) {
        if (lazy[idx] != 0) {
            seg[idx] += lazy[idx];
            if (l != r) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if (ql > r || qr < l) return;

        if (ql <= l && qr >= r) {
            seg[idx] += delta;
            if (l != r) {
                lazy[2 * idx + 1] += delta;
                lazy[2 * idx + 2] += delta;
            }
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
        if (lazy[idx] != 0) {
            seg[idx] += lazy[idx];
            if (l != r) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if (ql > r || qr < l) return INT_MAX;
        if (ql <= l && qr >= r) return seg[idx];

        int mid = (l + r) / 2;
        return min(queryUtil(2 * idx + 1, l, mid, ql, qr),
                   queryUtil(2 * idx + 2, mid + 1, r, ql, qr));
    }
};
