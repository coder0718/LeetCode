#include <iostream>
#include <vector>
#include <set>
#include <cstddef>
#include <stdint.h>

namespace leetcode {

class SolutionBase {
public:
    virtual ~SolutionBase() {}
    virtual int minimumTotal(
            const std::vector<std::vector<int> >& triangle, std::vector<int>* path) = 0;
};

class SolutionFirst : public SolutionBase {
public:
    virtual int minimumTotal(
            const std::vector<std::vector<int> >& triangle, std::vector<int>* path) {
        std::vector<std::vector<int> > dp(triangle);
        std::vector<std::vector<int> > dp_help(triangle);
        for (size_t i = 0; i < triangle.size(); ++i) {
            for (size_t j = 0; j < triangle[i].size(); ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = triangle[i][j];
                    dp_help[i][j] = 0;
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    dp_help[i][j] = 0;
                } else if (j == triangle[i].size() - 1) {
                    dp[i][j] = dp[i - 1][triangle[i - 1].size() - 1] + triangle[i][j];
                    dp_help[i][j] = triangle[i - 1].size() - 1;
                } else {
                    if (dp[i - 1][j - 1] < dp[i - 1][j]) {
                        dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                        dp_help[i][j] = j - 1;
                    } else {
                        dp[i][j] = dp[i - 1][j] + triangle[i][j];
                        dp_help[i][j] = j;

                    }
                }
            }
        }
        int min = 999999;
        int index = 0;
        for (uint32_t i = 0; i < dp[dp.size() - 1].size(); ++i) {
            if (dp[dp.size() - 1][i] < min) {
                min = dp[dp.size() - 1][i];
                index = i;
            }
        }

        for (int32_t i = triangle.size() - 1; i >= 0; --i) {
            path->push_back(triangle[i][index]);
            index  = dp_help[i][index];
        }
        return min;
    }
};

}
