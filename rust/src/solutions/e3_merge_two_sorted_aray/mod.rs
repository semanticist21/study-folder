// https://leetcode.com/problems/merge-two-sorted-lists/
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub fn merge_two_lists(
    list1: Option<Box<ListNode>>,
    list2: Option<Box<ListNode>>,
) -> Option<Box<ListNode>> {
    let mut list1 = list1;
    let mut list2 = list2;

    let mut new_list = Box::new(ListNode::new(0));
    let mut cur_node = new_list.as_mut();

    while list1.is_some() && list2.is_some() {
        if list1.is_some() && list2.is_none() {
            let list1_val = list1.as_ref().unwrap().val;
            let new_node = ListNode::new(list1_val);

            cur_node.next = Some(Box::new(new_node));
            cur_node = cur_node.next.as_ref().unwrap();
        }

        if list2.is_some() && list1.is_none() {
            
        }

    }

     None   
}

#[test]
fn test() {
    let l1 = Some(Box::new(ListNode {
        val: 1,
        next: Some(Box::new(ListNode {
            val: 2,
            next: Some(Box::new(ListNode { val: 4, next: None })),
        })),
    }));

    let l2 = Some(Box::new(ListNode {
        val: 1,
        next: Some(Box::new(ListNode {
            val: 3,
            next: Some(Box::new(ListNode { val: 4, next: None })),
        })),
    }));

    let expected = Some(Box::new(ListNode {
        val: 1,
        next: Some(Box::new(ListNode {
            val: 1,
            next: Some(Box::new(ListNode {
                val: 2,
                next: Some(Box::new(ListNode {
                    val: 3,
                    next: Some(Box::new(ListNode {
                        val: 4,
                        next: Some(Box::new(ListNode { val: 4, next: None })),
                    })),
                })),
            })),
        })),
    }));

    assert_eq!(merge_two_lists(l1, l2), expected);
}