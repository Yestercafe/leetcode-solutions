class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        const int N = startTime.size();
        int count = 0;
        for (int i = 0; i < N; ++i)
            if (startTime[i] <= queryTime && queryTime <= endTime[i])
                ++count;
        return count;
    }
};

