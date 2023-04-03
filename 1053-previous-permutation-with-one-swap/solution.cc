class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                int j = n - 1;
                while (arr[j] >= arr[i] || (j > 0 && arr[j - 1] == arr[j])) {
                    --j;
                }
                swap(arr[i], arr[j]);
                break;
            }
        }
        return arr;
    }
};

