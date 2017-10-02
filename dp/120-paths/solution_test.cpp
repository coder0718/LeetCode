#include <vector>
#include "leetcode/dp/120-paths/solution.h"
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

TEST_F(SoltuionTest, hasCrle) {
    std::vector<std::vector<int> > triangle;
    triangle.resize(3);
    triangle[0].resize(1);
    triangle[1].resize(2);
    triangle[2].resize(3);
    triangle[0][0] = -1;
    triangle[1][0] = -2;
    triangle[1][1] = -3;
    triangle[2][0] = -4;
    triangle[2][1] = 1;
    triangle[2][2] = 0;

    std::vector<std::vector<int> > paths;
    _solution->paths(triangle, &paths);

    return;
    for (int i = paths.size() - 1; i >= 0; --i) {
        std::cout << "************path******************" << std::endl;
        for (int j = 0; j < static_cast<int>(paths[i].size()); ++i) {
            std::cout << paths[i][j] << std::endl;
        }
    }
}

}  // namespace leetcode
