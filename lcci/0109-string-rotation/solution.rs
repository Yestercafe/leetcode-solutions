impl Solution {
    pub fn is_fliped_string(s1: String, s2: String) -> bool {
        if s1.len() != s2.len() {
            return false;
        }
        match (s1.clone() + &s1).find(&s2) {
            Some(_) => true,
            _ => false,
        }
    }
}

