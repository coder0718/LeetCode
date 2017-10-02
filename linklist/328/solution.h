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
    virtual ListNode* oddEvenList(ListNode* head) = 0; 
};

class SolutionFirst : public SolutionBase {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy_left  = new ListNode(-1);
        ListNode* dummy_right = new ListNode(-1);

        ListNode* left = dummy_left;
        ListNode* right = dummy_right;
        int number = 1;
        ListNode* p = head;
        while (p) {
           if (number % 2 == 0) {
               right->next = p;
               right = p;
           } else {
               left->next = p; 
               left = p;
           } 
           p = p->next;
           ++number;
        } 
        left->next = dummy_right->next;
        right->next = NULL;
        return dummy_left->next;
    }      
};

}
