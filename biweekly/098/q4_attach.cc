using ll = long long;

class SegTreeLazyRangeAdd {
    using T = ll;
    vector<T> tree;
    vector<bool> lazy;
    vector<int> *arr;
    int n, root, n4, end;

    void maintain(int cl, int cr, int p) {
        if (lazy[p]) {
            int cm = cl + (cr - cl) / 2;
            tree[p * 2] = (cm - cl + 1) - tree[p * 2];
            tree[p * 2 + 1] = (cr - cm) - tree[p * 2 + 1];
            lazy[p * 2] = !lazy[p * 2];
            lazy[p * 2 + 1] = !lazy[p * 2 + 1];
            lazy[p] = false;
        }
    }

    T range_sum(int l, int r, int cl, int cr, int p) {
        if (l <= cl && cr <= r) return tree[p];
        int m = cl + (cr - cl) / 2;
        T sum = 0;
        maintain(cl, cr, p);
        if (l <= m) sum += range_sum(l, r, cl, m, p * 2);
        if (r > m) sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
        return sum;
    }

    void range_add(int l, int r, T val, int cl, int cr, int p) {
        if (l <= cl && cr <= r) {
            lazy[p] = !lazy[p];
            tree[p] = (cr - cl + 1) - tree[p];
            return;
        }
        int m = cl + (cr - cl) / 2;
        maintain(cl, cr, p);
        if (l <= m) range_add(l, r, val, cl, m, p * 2);
        if (r > m) range_add(l, r, val, m + 1, cr, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    void build(int s, int t, int p) {
        if (s == t) {
            tree[p] = (*arr)[s];
            return;
        }
        int m = s + (t - s) / 2;
        build(s, m, p * 2);
        build(m + 1, t, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    public:
    explicit SegTreeLazyRangeAdd(vector<int> v) {
        n = v.size();
        n4 = n * 4;
        tree = vector<T>(n4, 0);
        lazy = vector<bool>(n4, false);
        arr = &v;
        end = n - 1;
        root = 1;
        build(0, end, 1);
        arr = nullptr;
    }

    T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

    void range_add(int l, int r, int val) { range_add(l, r, val, 0, end, root); }
};

class Solution {
    public:
        vector<long long> handleQuery(vector<int>& v1, vector<int>& v2, vector<vector<int>>& qs) {
            int n = v1.size();
            SegTreeLazyRangeAdd st(v1);

            vector<long long> ans;
            long long sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += v2[i];
            }
            for (auto& q : qs) {
                if (q[0] == 1) {
                    int l = q[1], r = q[2];
                    st.range_add(l, r, 1);
                } else if (q[0] == 2) {
                    int p = q[1];
                    int cnt = st.range_sum(0, n - 1);
                    sum += (long long) cnt * p;
                } else { // if (q[0] == 3)
                    ans.push_back(sum);
                }
            }

            return ans;
        }
};

