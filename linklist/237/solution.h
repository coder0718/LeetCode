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
    virtual void deleteNode(ListNode* node) = 0; 
};

class SolutionFirst : public SolutionBase {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL || node->next == NULL) {
            return;
        }

        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
    }      
};

}
