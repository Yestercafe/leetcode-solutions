impl Solution {
    pub fn min_number_of_hours(initial_energy: i32, initial_experience: i32, energy: Vec<i32>, experience: Vec<i32>) -> i32 {
        let mut eng = initial_energy;
        let mut exp = initial_experience;
        let n = energy.len();
        let mut ans = 0;
        for i in 0..n {
            if eng <= energy[i] {
                ans += energy[i] - eng + 1;
                eng = energy[i] + 1;
            }
            if exp <= experience[i] {
                ans += experience[i] - exp + 1;
                exp = experience[i] + 1;
            }
            exp += experience[i];
            eng -= energy[i];
        }

        ans
    }
}

