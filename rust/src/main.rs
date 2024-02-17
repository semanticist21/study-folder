mod solutions;

fn main() {
    let rs = solutions::m1_atoi::my_atoi("   00++0+  42  ".to_string());
    let rs2 = solutions::m1_atoi::my_atoi("   +42+3  ".to_string());
    let rs3 = solutions::m1_atoi::my_atoi("900000000000000  ".to_string());

    println!("rs: {}", rs);
    println!("rs2: {}", rs2);
    println!("rs3: {}", rs3);
}
