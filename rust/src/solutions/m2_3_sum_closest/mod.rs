pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
    let mut sums: Vec<i32> = vec![];

    for i in 0..nums.len() {
        for j in i + 1..nums.len() {
            for k in j + 1..nums.len() {
                sums.push(nums[i] + nums[j] + nums[k]);
            }
        }
    }

    let mut closest = sums[0];

    sums.iter().for_each(|x| {
        let abs_val: i32 = (x - target).abs();

        if abs_val < (closest-target).abs() {
            closest = *x;
        }
    });

    closest
}

#[test]
fn test_three_sum_closest() {
    let nums = vec![1, 1, 1, 0];
    let target = -100;
    let val = three_sum_closest(nums, target);
    assert_eq!(val, 2);
}
