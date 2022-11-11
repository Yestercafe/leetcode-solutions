 fn convert_time_to_int(t: &str) -> i32 {
    let mut a = t.split(':').map(|s| s.parse::<i32>().unwrap());
    match (a.next(), a.next()) {
        (Some(h), Some(m)) => h * 60 + m,
        _ => -1,
    }
}

impl Solution {
    pub fn have_conflict(event1: Vec<String>, event2: Vec<String>) -> bool {
        let s1 = convert_time_to_int(&event1[0]);
        let e1 = convert_time_to_int(&event1[1]);
        let s2 = convert_time_to_int(&event2[0]);
        let e2 = convert_time_to_int(&event2[1]);

        if s1 == s2 {
            true
        } else if s1 < s2 && e1 >= s2 {
            true
        } else if s2 < s1 && e2 >= s1 {
            true
        } else {
            false
        }
    }
}

