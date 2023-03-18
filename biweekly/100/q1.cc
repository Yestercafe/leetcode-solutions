class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        money -= children;
        int seven = money / 7;
        int remain = money % 7;
        if (seven == children && remain > 0) return children - 1;
        if (seven == children && remain == 0) return children;
        if (seven == children - 1 && remain == 3) return children - 2;
        if (seven > children) return children - 1;
        if (seven < children) return seven;
        return -1;
    }
};

