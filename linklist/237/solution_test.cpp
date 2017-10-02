#include <vector>
#include "leetcode/linklist/237/solution.h"
#include "thirdparty/gtest/gtest.h"

namespace leetcode {

void buildList(ListNode* dummy, const std::vector<int>& input) {
    ListNode* p = dummy;

    int count = 0;
    ListNode* last_node = NULL;
    for (size_t i = 0; i < input.size(); ++i) {
        p->next = new ListNode(input[i]);
        p = p->next;
        ++count;
        if (count == 2) {
            last_node = p;
        }

  
    }
    p->next = last_node;
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
    output->push_back(5);
    output->push_back(1);
    output->push_back(6);
    output->push_back(3);
    output->push_back(2);
}

class SoltuionTest : public ::testing::Test {
protected:     
    virtual void SetUp() {
        _solution = new SolutionFirst();
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

TEST_F(SoltuionTest, hasCrle) {
    ListNode* dummy_one = new ListNode(0);
    std::vector<int> input;
    buildVector(2, &input);
    buildList(dummy_one, input);
    _solution->deleteNode(dummy_one->next); 
    destroyList(dummy_one);
}

}  // namespace leetcode 
