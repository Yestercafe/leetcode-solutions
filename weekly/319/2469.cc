class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> r(2);
        r[0] = celsius + 273.15;
        r[1] = celsius * 1.8 + 32.;
        return r;
    }
};
