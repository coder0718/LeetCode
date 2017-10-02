#include <vector>
#include "leetcode/dp/494/solution.h"
#include "thirdparty/gtest/gtest.h"

namespace leetcode {

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

TEST_F(SoltuionTest, minPathSum) {
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);

    int total_num = _solution->findTargetSumWays(nums, 3);
    std::cout << "total_num:" << total_num << std::endl;
}

}  // namespace leetcode
