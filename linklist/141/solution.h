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
    virtual bool hasCycle(ListNode* head) = 0;
};

class SolutionFirst : public SolutionBase {
public:
    bool hasCycle(ListNode* head) {
        std::set<ListNode*> visited;
        std::set<ListNode*>::iterator iter;
        while (head != NULL) {
            iter = visited.find(head);
            if (iter == visited.end()) {
                visited.insert(head);
            } else {
                return true;
            }
            head = head->next;
        }
        return false; 
    }      
};

class SolutionSecond : public SolutionBase {
public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

}
