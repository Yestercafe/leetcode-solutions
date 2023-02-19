struct Class {
    int p, t;
    Class(const vector<int>& v) : p{v[0]}, t{v[1]} {}
    Class(int p, int t) : p{p}, t{t} {}
    friend bool operator<(const Class& lhs, const Class& rhs) {
        return (double) (lhs.p + 1) / (lhs.t + 1) - (double) lhs.p / lhs.t <
               (double) (rhs.p + 1) / (rhs.t + 1) - (double) rhs.p / rhs.t;
    }
    Class& operator++() {
        ++p, ++t;
        return *this;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& cs, int es) {
        priority_queue<Class> pq;
        for (auto& v : cs) {
            pq.push(v);
        }
        while (es--) {
            auto pt = pq.top();
            pq.pop();
            pq.push(++pt);
        }
        double suma = 0.0;
        while (!pq.empty()) {
            suma += (double) pq.top().p / pq.top().t;
            pq.pop();
        }
        return suma / cs.size();
    }
};

