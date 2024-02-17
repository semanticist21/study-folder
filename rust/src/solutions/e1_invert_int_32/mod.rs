pub fn _reverse_i32(x: i32) -> i32 {
    x.to_string()
        .chars()
        .filter(|c| !c.is_numeric())
        .chain(x.to_string().chars().filter(|x| x.is_numeric()).rev())
        .collect::<String>()
        .parse::<i32>()
        .unwrap_or(0)
}
