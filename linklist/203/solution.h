#include <iostream>
#include <set> 
#include <cstddef> 
#include <stdint.h>

namespace leetcode {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SolutionBase {
public:
    virtual ~SolutionBase() {}
    virtual ListNode* removeElements(ListNode* head, int val) = 0; 
};

class SolutionFirst : public SolutionBase {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur) {
            if (cur->val == val) {
               pre->next = cur->next; 
            } else {
               pre = cur;
            }
            cur = cur->next;
        } 
        return dummy->next;
    }      
};

}
