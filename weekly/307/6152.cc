class Solution {
public:
    int minNumberOfHours(int eng, int exp, vector<int>& energy, vector<int>& experience) {
        const int N = energy.size();
        int reqEng = 0, reqExp = 0;
        for (int i = 0; i < N; ++i) {
            if (eng <= energy[i]) {
                reqEng += energy[i] + 1 - eng;
                eng = energy[i] + 1;
            }
            if (exp <= experience[i]) {
                reqExp += experience[i] + 1 - exp;
                exp = experience[i] + 1;
            }
            eng -= energy[i];
            exp += experience[i];
        }
        cout << reqEng << " " << reqExp << endl;
        return reqEng + reqExp;
    }
};
