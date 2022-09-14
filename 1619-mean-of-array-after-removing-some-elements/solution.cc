class Solution {
public:
    double trimMean(vector<int>& arr) {
        int N = arr.size();
        double ans = 0;
        for (auto& a : arr) ans += a;
        nth_element(arr.begin(), arr.begin() + N / 20, arr.end(), less<int>{});
        for (int i = 0; i < N / 20; ++i) ans -= arr[i];
        nth_element(arr.begin(), arr.begin() + N / 20, arr.end(), greater<int>{});
        for (int i = 0; i < N / 20; ++i) ans -= arr[i];
        return ans / (N / 10 * 9);
    }
};

