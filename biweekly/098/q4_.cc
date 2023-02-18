// 提交的代码纪念：

template <typename T>
class SegTreeLazyRangeAdd {
  vector<T> tree, lazy;
  vector<T> *arr;
  int n, root, n4, end;

  void maintain(int cl, int cr, int p) {
    int cm = cl + (cr - cl) / 2;
    if (cl != cr && lazy[p]) {
      lazy[p * 2] += lazy[p];
      lazy[p * 2 + 1] += lazy[p];
      if (lazy[p] % 2) {
          tree[p * 2] = (cm - cl + 1) - tree[p * 2];
          tree[p * 2 + 1] += (cr - cm) - tree[p * 2 + 1];  // <<< 因为这里多了一个小小的加号与 4 题无缘
      }
      lazy[p] = 0;
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
      lazy[p] += val;
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
  explicit SegTreeLazyRangeAdd<T>(vector<T> v) {
    n = v.size();
    n4 = n * 4;
    tree = vector<T>(n4, 0);
    lazy = vector<T>(n4, 0);
    arr = &v;
    end = n - 1;
    root = 1;
    build(0, end, 1);
    arr = nullptr;
  }

  void show(int p, int depth = 0) {
    if (p > n4 || tree[p] == 0) return;
    show(p * 2, depth + 1);
    for (int i = 0; i < depth; ++i) putchar('\t');
    printf("%d-%d:%d\n", p, tree[p], lazy[p]);
    show(p * 2 + 1, depth + 1);
  }

  T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

  void range_add(int l, int r, int val) { range_add(l, r, val, 0, end, root); }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& v1, vector<int>& v2, vector<vector<int>>& qs) {
        int n = v1.size();
        SegTreeLazyRangeAdd<int> st(v1);
        
//         st.show(1);
//         st.range_add(1, 4, 1);
//         cout << st.range_sum(0, n) << endl;
//         st.show(1);
//         st.range_add(2, 5, 1);
//         cout << st.range_sum(0, n) << endl;
//         st.show(1);
        
        
//         return {};
        
        
        
        
        vector<long long> ans;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += v2[i];
        }
        for (auto q : qs) {
            if (q[0] == 1) {
                int l = q[1], r = q[2];
                st.range_add(l, r, 1);
            } else if (q[0] == 2) {
                int p = q[1];
                int cnt = st.range_sum(0, n);
                sum += (long long) cnt * p;
            } else { // if (q[0] == 3)
                ans.push_back(sum);
            }
        }
        
        return ans;
    }
};

