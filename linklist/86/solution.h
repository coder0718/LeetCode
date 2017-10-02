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
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftDummy = new ListNode(0);
        ListNode *rightDummy = new ListNode(0);

        ListNode* left = leftDummy;
        ListNode* right = rightDummy;

        while (head != NULL) {
            std::cout << "scan:" << head->val << std::endl;
            if (head->val < x) {
                left->next = head;
                left = head;
            } else {
                right->next = head;
                right = head;
            }
            head = head->next;
        }

        left->next = rightDummy->next;
        ListNode* root = leftDummy->next;
        right->next = NULL;

        delete leftDummy;
        delete rightDummy;
        return root; 
    }      
};

}
