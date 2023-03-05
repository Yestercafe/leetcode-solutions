use std::cmp::min;

impl Solution {
    pub fn min_operations_max_profit(customers: Vec<i32>, boarding_cost: i32, running_cost: i32) -> i32 {
        let mut round = 0;
        let mut profit = 0;
        let mut max_profit = 0;
        let mut ans = -1;
        let mut pending = 0;
        for c in customers {
            round += 1;
            pending += c;
            let this_round_c = min(4, pending);
            pending -= this_round_c;
            profit += this_round_c * boarding_cost - running_cost;
            if profit > max_profit {
                max_profit = profit;
                ans = round;
            }
        }
        while pending != 0 {
            round += 1;
            let this_round_c = min(4, pending);
            pending -= this_round_c;
            profit += this_round_c * boarding_cost - running_cost;
            if profit > max_profit {
                max_profit = profit;
                ans = round;
            }
        }
        return ans;
    }
}

