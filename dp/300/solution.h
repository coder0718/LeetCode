#include <algorithm>
#include <iostream>
#include <vector>
#include <cstddef>
#include <stdint.h>

namespace leetcode {

class SolutionBase {
public:
    virtual ~SolutionBase() {}
    virtual int lengthOfLIS(std::vector<int>& nums) = 0;
};

class SolutionFirst : public SolutionBase {
public:
    virtual int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        std::vector<int> dp;
        dp.resize(nums.size());
        
        dp[0] = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            int max = 0;
            for (size_t j = 0; j < i ; ++j) {
                if (dp[j] > max && nums[j] < nums[i]) {
                    max = dp[j];
                }
            }
            dp[i] = max + 1;
        }
        
        return *std::max_element(dp.begin(), dp.end());
    }
};

}
