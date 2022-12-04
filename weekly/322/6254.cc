class Solution {
    using ll = long long;
public:
    long long dividePlayers(vector<int>& skill) {
        auto n = skill.size();
        map<ll, ll> cnts;
        ll total {};
        for (const auto& s : skill) {
            total += s;
            ++cnts[s];
        }
        if (total % (n / 2) != 0) return -1;
        ll avg = total / (n / 2);

        ll reaction {};
        while (!cnts.empty()) {
            auto pair { cnts.begin() };
            if (2 * pair->first == avg) {
                if (pair->second & 1) return -1;
                reaction += (pair->second / 2) * pair->first * pair->first;
                cnts.erase(pair);
            } else {
                auto fnd { cnts.find(avg - pair->first) };
                if (fnd == cnts.end()) return -1;
                else if (fnd->second != pair->second) return -1;
                reaction += pair->second * pair->first * fnd->first;
                cnts.erase(pair);
                cnts.erase(fnd);
            }
        }
        return reaction;
    }
};

