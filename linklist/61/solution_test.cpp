#include <vector>
#include "leetcode/linklist/61/solution.h"
#include "thirdparty/gtest/gtest.h"

namespace leetcode {

void buildList(ListNode* dummy, const std::vector<int>& input) {
    ListNode* p = dummy;
    for (size_t i = 0; i < input.size(); ++i) {
        p->next = new ListNode(input[i]);
        p = p->next;
    }
    p->next = NULL;
}

void destroyList(ListNode* dummy) {
    ListNode* p = dummy;
    while (!p) {
        ListNode *temp = p;
        p = p->next;
        delete temp;
    }
}

void buildVector(int k, std::vector<int>* output) {
    for (int i = 1; i <= k; ++i) {
        output->push_back(i);
    }
}

class SoltuionTest : public ::testing::Test {
protected:     
    virtual void SetUp() {
        _solution = new Solution();
    }

    virtual void TearDown() {
        if (_solution) {
            delete _solution;
            _solution = NULL;
        }
    }

protected:
    Solution* _solution;    
};

TEST_F(SoltuionTest, reverseBetween) {
    ListNode* dummy_one = new ListNode(0);
    std::vector<int> input;
    buildVector(2, &input);
    buildList(dummy_one, input);
    ListNode* head = _solution->rotateRight(dummy_one->next, 3); 
    while (head) {
        std::cout << head->val << std::endl;
        head = head->next;
    }  
    destroyList(dummy_one);
}

}  // namespace leetcode 
