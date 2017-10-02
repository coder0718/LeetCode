#include <iostream>
#include <vector>
#include <set>
#include <cstddef>
#include <stdint.h>

namespace leetcode {

class SolutionBase {
public:
    virtual ~SolutionBase() {}
    virtual int minPathSum(std::vector<std::vector<int> >& grid) = 0;
};

class SolutionFirst : public SolutionBase {
public:
    virtual int minPathSum(std::vector<std::vector<int> >& grid) {
        std::vector<std::vector<int> > dp(grid);
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else if (i == 0 && j > 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                } else if (i > 0 && j == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                } else {
                     dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
                }
            }
        }
        return dp[grid.size() - 1][grid[grid.size() - 1].size() - 1];
    }
};

}
