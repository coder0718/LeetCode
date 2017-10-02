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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = getLength(head);
        if (!head || !head->next || len == k || len == 0) {
            return head;
        }
        k = k % len;
        ListNode* a = NULL;
        ListNode* b = NULL;
        if (!findBetween(head, a, b, k)) {
            return NULL;
        }
        b->next = head;
        ListNode* root = a->next;
        a->next = NULL;
        return root;       
    }

private:
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }

    bool findBetween(ListNode* head, ListNode* &a, ListNode* &b, int k) {
        if (!head) {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < k; ++i) {
            if (fast) {
                fast = fast->next;
            } else {
                return false;
            }
        }
        
        while (fast!=NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        a = slow;
        b = fast;
        return true;
    }
};
}
