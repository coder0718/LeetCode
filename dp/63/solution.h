#include <iostream>
#include <vector>
#include <set>
#include <cstddef>
#include <stdint.h>

namespace leetcode {

class SolutionBase {
public:
    virtual ~SolutionBase() {}
    virtual int uniquePathsWithObstacles(
            std::vector<std::vector<int> >& obstacleGrid) = 0;
};

class SolutionFirst : public SolutionBase {
public:
    virtual int uniquePathsWithObstacles(
            std::vector<std::vector<int> >& obstacleGrid) {
        std::vector<std::vector<int> > dp(obstacleGrid);
        for (size_t i = 0; i < obstacleGrid.size(); ++i) {
            for (size_t j = 0; j < obstacleGrid[i].size(); ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else if (i > 0 && j == 0) {
                    dp[i][j] = dp[i - 1][j];
                } else if (i == 0 && j > 0) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[dp.size() - 1][dp[dp.size() - 1].size() - 1];
    }
};

}
