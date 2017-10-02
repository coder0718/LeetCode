#include <iostream>
#include <cstddef> 

namespace leetcode {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* it = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                it->next = l1;
                l1 = l1->next;
            } else {
                it->next = l2;
                l2 = l2->next;
            }
            it = it->next;
        }
        it->next = l1 ? l1 : l2;
        return dummy.next;  
    }
};

}
