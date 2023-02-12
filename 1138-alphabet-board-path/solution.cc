class Solution {
public:
    string alphabetBoardPath(string target) {
        pair<int, int> pos[26];
        for (char c = 'a'; c <= 'z'; ++c) {
            pos[c - 'a'].first = (c - 'a') / 5;
            pos[c - 'a'].second = (c - 'a') % 5;
        }
        int curX = 0, curY = 0;
        string ans;
        for (char nxt : target) {
            auto [nx, ny] = pos[nxt - 'a'];
            if (curX == 5 && curY == 0 && nxt == 'z') {
                ans.push_back('!');
                continue;
            } else if (curX == 5 && curY == 0) {
                --curX;
                ans.push_back('U');
            } else if (nxt == 'z') {
                --nx;
            }
            
            int diffX = nx - curX;
            int diffY = ny - curY;
            if (diffX > 0) {
                ans += string(diffX, 'D');
            } else if (diffX < 0) {
                ans += string(-diffX, 'U');
            }
            curX = nx;

            if (diffY > 0) {
                ans += string(diffY, 'R');
            } else if (diffY < 0) {
                ans += string(-diffY, 'L');
            }
            curY = ny;

            if (nxt == 'z') {
                ans.push_back('D');
                ++curX;
            }

            ans.push_back('!');
        }
        return ans;
    }
};

