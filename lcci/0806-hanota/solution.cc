class Solution {
    void move(vector<int>& from, vector<int>& to, vector<int>& tmp, int remain) {
        if (remain == 0) {
            return;
        }

        move(from, tmp, to, remain - 1);
        auto plate = from.back();
        from.pop_back();
        to.push_back(plate);
        move(tmp, to, from, remain - 1);
    }
public:
    void hanota(vector<int>& a, vector<int>& b, vector<int>& c) {
        move(a, c, b, a.size());
    }
};

