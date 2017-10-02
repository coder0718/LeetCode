#include <vector>
#include "leetcode/depth-first-search/templet/solution.h"
#include "thirdparty/gtest/gtest.h"

namespace leetcode {

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

TEST_F(SoltuionTest, pick) {
    std::vector<int> picked;
    _solution->pick(5, picked, 3);
}

}  // namespace leetcode 
