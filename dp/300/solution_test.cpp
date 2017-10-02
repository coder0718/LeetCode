#include <vector>
#include "leetcode/dp/300/solution.h"
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
    std::vector<int> input;
    input.push_back(2);
    input.push_back(4);
    input.push_back(6);
    input.push_back(7);
    input.push_back(1);
    input.push_back(0);
    input.push_back(8);
    input.push_back(9);
    input.push_back(6);

    int length_of_lis = _solution->lengthOfLIS(input);
    std::cout << "length_of_lis:" << length_of_lis << std::endl;
}

}  // namespace leetcode
