pub fn is_valid(s: String) -> bool {
    let mut stack: Vec<char> = vec![];
    let mut is_valid = true;

    s.chars().for_each(|c| {
        if is_valid {
            match c {
                '(' | '{' | '[' => stack.push(c),
                ')' => {
                    if stack.pop() != Some('(') {
                        is_valid = false;
                    }
                }
                '}' => {
                    if stack.pop() != Some('{') {
                        is_valid = false;
                    }
                }
                ']' => {
                    if stack.pop() != Some('[') {
                        is_valid = false;
                    }
                }
                _ => is_valid = false,
            }
        }
    });

    if stack.len() > 0 {
        is_valid = false;
    }

    is_valid
}

#[test]
fn test_is_valid() {
    let s = "([)]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "{[]}".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([)]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "([])".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "([])".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "([])".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "([])".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "([])".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "([])".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "([])".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "([])".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "([])".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "([])".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "([])".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([]".to_string();
    assert_eq!(is_valid(s), false);
    let s = "([])".to_string();
    assert_eq!(is_valid(s), true);
    let s = "([]".to_string();
    assert_eq!(is_valid(s), false);
}
