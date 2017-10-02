#include <iostream>
#include <vector>
#include <set>
#include <cstddef>
#include <stdint.h>

namespace leetcode {

class SolutionBase {
public:
    virtual ~SolutionBase() {}
    virtual  int findTargetSumWays(std::vector<int>& nums, int S) = 0;
};

class SolutionFirst : public SolutionBase {
public:
    virtual  int findTargetSumWays(std::vector<int>& nums, int S) {
        if (nums.empty()) 
            return 0;
        int cnt = 0;
        dfs(nums, S, 0, 0, &cnt);
        return cnt;
    }

private:
    void dfs(std::vector<int>& nums, int s, int k, int sum, int *cnt) {
        // s:3 k:5 sum:3 cnt:0
        std::cout << "s:" << s 
                  << " k:" << k
                  << " sum:" << sum
                  << " cnt:" << *cnt 
                  << std::endl;
        if (k == static_cast<int>(nums.size())) {
            if (sum == s) {
                (*cnt)++;
            }
            return;
        }
        
        dfs(nums, s, k + 1, sum + nums[k], cnt);
        dfs(nums, s, k + 1, sum - nums[k], cnt);
    }
};

}
