#define ll long long
#define maxn 100000
#define dl (d << 1)
#define dr (d << 1 | 1)

struct node {
    ll l, r, sum, tag;
    node() : l(0), r(0), sum(0), tag(0) {}
};
vector<node> sgt;

void pushup(ll d) { sgt[d].sum = sgt[dl].sum + sgt[dr].sum; }
void pushdown(ll d) {
    sgt[dl].sum += (sgt[dl].r - sgt[dl].l + 1) * sgt[d].tag;
    sgt[dr].sum += (sgt[dr].r - sgt[dr].l + 1) * sgt[d].tag;
    sgt[dl].tag += sgt[d].tag;
    sgt[dr].tag += sgt[d].tag;
    sgt[d].tag = 0;
}

void add(ll d, ll l, ll r, ll k) {
    if (sgt[d].l >= l && sgt[d].r <= r) {
        sgt[d].sum += k * (sgt[d].r - sgt[d].l + 1);
        sgt[d].tag += k;
        return;
    }
    int mid = (sgt[d].l + sgt[d].r) >> 1;
    if (sgt[d].tag) pushdown(d);
    if (l <= mid) add(dl, l, r, k);
    if (r > mid) add(dr, l, r, k);
    pushup(d);
}

void build(ll d, ll l, ll r) {
    sgt[d].l = l;
    sgt[d].r = r;
    sgt[d].tag = 0;
    if (l == r) {
        sgt[d].sum = 0;
        return;
    }
    ll mid = (l + r) >> 1;
    build(dl, l, mid);
    build(dr, mid + 1, r);
    pushup(d);
}

ll query(ll d, ll l, ll r) {
    if (sgt[d].l >= l && sgt[d].r <= r)
        return sgt[d].sum;
    if (sgt[d].tag) pushdown(d);
    ll ret = 0;
    int mid = (sgt[d].l + sgt[d].r) >> 1;
    if (l <= mid) ret += query(dl, l, r);
    if (r > mid) ret += query(dr, l, r);
    return ret;
}

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        sgt.assign((s.length() << 2) + 5, {});
        build(1, 1, s.length());
        for (auto& t : shifts) {
            add(1, t[0] + 1, t[1] + 1, t[2] ? +1 : -1);
            // cout << t[0] + 1 << " " << query(1, t[0] + 1, t[1] + 1) << endl;;
        }
        
        for (int i = 0; i < s.length(); ++i) {
            int add = query(1, i + 1, i + 1) % 26;
            if (add < 0) add += 26;
            // cout << add << endl;
            s[i] = 'a' + (s[i] - 'a' + add) % 26;
        }
        // cout << s << endl;
        return s;
    }
};
