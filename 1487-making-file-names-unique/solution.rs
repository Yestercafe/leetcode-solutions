use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn get_folder_names(names: Vec<String>) -> Vec<String> {
        let mut set = HashSet::<String>::new();
        let mut cnt = HashMap::<String, i32>::new();
        let mut ans = vec![];

        for name in names {
            if !set.contains(&name) {
                set.insert(name.clone());
                ans.push(name);
                continue;
            }
            let mut k: i32;
            if let Some(a) = cnt.get(&name) {
                k = a.clone();
            } else {
                k = 1;
            }
            let mut new_name = String::from(format!("{}({})", &name, k));
            while set.contains(&new_name) {
                k += 1;
                new_name = String::from(format!("{}({})", &name, k));
            }
            set.insert(new_name.clone());
            ans.push(new_name);
            cnt.insert(name.clone(), k + 1);
        }

        ans
    }
}

