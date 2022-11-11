fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

impl Solution {
    pub fn subarray_gcd(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut r = 0;

        for i in 0usize..n {
            let mut g = 0;
            for j in i..n {
                g = gcd(g, nums[j]);
                if g % k != 0 { break; }
                if g == k { r += 1; }
            }
        }
        
        r
    }
}

