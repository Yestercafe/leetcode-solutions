class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;

        while (r > 0) {
            if (arr[r - 1] <= arr[r]) {
                --r;
            } else {
                break;
            }
        }
        if (r <= 0) return 0;

        // right hand side: [r, n - 1]
        int ans = r;

        while (l < n - 1) {
            int lv = arr[l];
            while (r < n && arr[r] < lv) ++r;
            // cout << l << ' ' << r << endl;
            ans = min(ans, r - l - 1);
            if (arr[l] > arr[l + 1]) break;
            ++l;
        }

        return ans;
    }
};

