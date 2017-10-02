#include <iostream>
#include <vector> 
#include <cstddef> 
#include <stdint.h>

namespace leetcode {

// 从N个数中选出M个数
class SolutionBase {
public:
    virtual ~SolutionBase() {}

    // n,元素总数
    // picked, 已选元素的序号列表
    // toPick,还需要选择的元素个数
    virtual void pick(int n, std::vector<int>& picked, int toPick) = 0;
};

class SolutionFirst : public SolutionBase {
public:
    void pick(int n, std::vector<int>& picked, int toPick) {
        if (toPick == 0) {
            output(picked);
            return;
        }
        int smallest = picked.empty() ? 0 : picked.back() + 1;
        for (int next = smallest; next < n; ++next) {
            picked.push_back(next);
            pick(n, picked, toPick - 1);
            picked.pop_back();
        }
    }

private:
    void output(const std::vector<int>& picked) {
        std::cout << "-----------------------------" << std::endl;
        for (size_t i = 0; i < picked.size(); ++i) {
            std::cout << picked[i] << std::endl;
        }
    } 
};

}
