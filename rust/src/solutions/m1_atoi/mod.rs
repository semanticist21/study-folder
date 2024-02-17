// https://leetcode.com/problems/string-to-integer-atoi/description/
pub fn my_atoi(s: String) -> i32 {
    let mut pure: Vec<char> = vec![];
    let mut impure: Vec<char> = vec![];

    let mut is_neg = false;

    let mut is_break = false;

    s.chars().for_each(|c| {
        if is_break {
            return;
        }

        let is_ws = c.is_whitespace();
        let is_n = c >= '1' && c <= '9';
        let is_flag = c == '+' || c == '-';
        let is_zero = c == '0';

        let is_other = !is_ws && !is_n && !is_flag && !is_zero;

        if is_other {
            is_break = true;
            return;
        }

        if is_ws {
            if !pure.is_empty() || !impure.is_empty() {
                is_break = true;
            }
            return;
        }

        if is_zero {
            if !pure.is_empty() {
                pure.push(c);
            } else {
                impure.push(c);
            }

            return;
        }

        if is_flag {
            let is_brk_cond = !pure.is_empty() || !impure.is_empty();

            if is_brk_cond {
                is_break = true;
                return;
            }

            if c == '-' {
                is_neg = true;
            }

            impure.push(c);
            return;
        }

        pure.push(c);
    });

    let str = pure.iter().collect::<String>();
    let slice_rng = str.len().min(10);

    let sliced_int = &str[str.len() - slice_rng..str.len()]
        .parse::<i64>()
        .unwrap_or(0);

    let is_over = str.len() > 10;
    let rs: i32;

    if is_neg {
        if -sliced_int < i32::min_value() as i64 || is_over {
            rs = i32::MIN;
        } else {
            rs = -sliced_int.to_owned() as i32;
        }
    } else {
        if *sliced_int > i32::max_value() as i64 || is_over {
            rs = i32::MAX;
        } else {
            rs = sliced_int.to_owned() as i32;
        }
    }

    rs
}
