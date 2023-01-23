class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int used = 0;
        double tax = 0;
        for (auto& v : brackets) {
            if (v[0] < income) {
                tax += (v[0] - used) * v[1];
                used = v[0];
            } else {
                tax += (income - used) * v[1];
                break;
            }
        }
        return tax / 100;
    }
};

