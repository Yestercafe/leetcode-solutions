class Solution {
    string binary(int a) {
        string str;
        while (a != 0) {
            str.push_back(a % 2 + '0');
            a /= 2;
        }
        reverse(str.begin(), str.end());
        return str;
    }
public:
    string convertDateToBinary(string date) {
        int y = std::stoi(date.substr(0, 4));
        int m = std::stoi(date.substr(5, 2));
        int d = std::stoi(date.substr(8, 2));
        return binary(y) + "-" + binary(m) + "-" + binary(d);
    }
};

