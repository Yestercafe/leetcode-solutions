class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> cnt;
        for (auto& s : cpdomains) {
            stringstream ss1;
            ss1 << s;
            int times;
            string domain;
            ss1 >> times >> domain;
            
            int pos;
            while ((pos = domain.find('.')) != domain.npos) {
                // cout << domain << endl;
                cnt[domain] += times;
                domain.erase(0, pos + 1);
            }
            cnt[domain] += times;
            // cout << domain << endl;
        }
        
        vector<string> r(cnt.size());
        transform(cnt.begin(), cnt.end(), r.begin(), [](const pair<string, int>& p) {
            return to_string(p.second) + " " + p.first;
        });
        return r;
    }
};

