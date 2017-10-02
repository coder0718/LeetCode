#include <vector>
#include "leetcode/linklist/92/solution.h"
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

class SoltuionSecondTest : public ::testing::Test {
protected:     
    virtual void SetUp() {
        _solution = new SolutionThree();
    }

    virtual void TearDown() {
        if (_solution) {
            delete _solution;
            _solution = NULL;
        }
    }

protected:
    SolutionBase* _solution;    
};

TEST_F(SoltuionSecondTest, reverseBetween) {
    ListNode* dummy = new ListNode(0);
    std::vector<int> input;
    buildVector(5, &input);
    buildList(dummy, input);
    ListNode* new_node = _solution->reverseBetween(dummy->next, 2, 4);
    EXPECT_EQ(new_node->next->val, 4);
    EXPECT_EQ(new_node->next->next->val, 3);
    EXPECT_EQ(new_node->next->next->next->val, 2);
    destroyList(dummy);
}

}  // namespace leetcode 
