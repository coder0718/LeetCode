#include <cstddef> 

namespace leetcode {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SolutionBase {
public:
    virtual ~SolutionBase() { }
    virtual ListNode* reverseBetween(ListNode* head, int m, int n) = 0;
};
    
class SolutionFirst : public SolutionBase {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next) return head;

        ListNode* pre_from = findNode(head, m - 1);
        ListNode* from = findNode(head, m);
        ListNode* after_to = findNode(head, n + 1);
        ListNode* to = findNode(head, n);

        ListNode* cur = from;
        ListNode* pre = after_to;
        to->next = NULL;
        while (cur != NULL) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        if (pre_from) {
            pre_from->next = pre;
            return head;
        } else {
            return pre;
        }
    }

private:
    ListNode* findNode(ListNode* head, int k) {
        if (k == 0) return NULL;
        int count = 1;
        while (head) {
            if (count == k) return head;
            head = head->next;
            ++count;
        }
        return NULL;
    }
};

class SolutionSecond : public SolutionBase {
public:
    void reverse(ListNode *head) {
        ListNode *prev = NULL;
        while (head != NULL) {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
    }

    ListNode *findkth(ListNode *head, int k) {
        for (int i = 0; i < k; i++) {
            if (head == NULL) {
                return NULL;
            }
            head = head->next;
        }
        return head;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *mth_prev = findkth(dummy, m - 1);
        ListNode *mth = mth_prev->next;
        ListNode *nth = findkth(dummy, n);
        ListNode *nth_next = nth->next;
        nth->next = NULL;

        reverse(mth);
        mth_prev->next = nth;
        mth->next = nth_next;
        return dummy->next;
    }
};

class SolutionThree : public SolutionBase {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* tail = NULL;
        return reverse(head, m, n, tail);    
    }

private:
       ListNode* reverse(ListNode* head, int m, int n, ListNode* &tail) {
        if (m > 1) {
            head->next = reverse(head->next, m - 1, n - 1, tail);
            return head;
        } else if (n > 1) {
            ListNode* node = reverse(head->next, m, n - 1, tail);
            head->next->next = head;
            head->next = tail;
            return node;
        } else {
            tail = head->next;
            return head;
        }
    } 
};

}
