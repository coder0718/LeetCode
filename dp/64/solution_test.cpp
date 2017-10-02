#include <vector>
#include "leetcode/dp/64/solution.h"
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
    std::vector<std::vector<int> > grid;
    grid.resize(3);
    grid[0].resize(3);
    grid[1].resize(3);
    grid[2].resize(3);
    grid[0][0] = 3;
    grid[0][1] = 1;
    grid[0][2] = 0;
    grid[1][0] = 1;
    grid[1][1] = 0;
    grid[1][2] =  3;
    grid[2][0] = -4;
    grid[2][1] = 1;
    grid[2][2] = 2;

    int min = _solution->minPathSum(grid);
    std::cout << "min:" << min << std::endl;
}

}  // namespace leetcode
