#include <iostream>
#include <vector>
#include <set>
#include <cstddef>
#include <stdint.h>

namespace leetcode {

class SolutionBase {
public:
    virtual ~SolutionBase() {}
    virtual void paths(
            const std::vector<std::vector<int> >& triangle,
            std::vector<std::vector<int> >* paths) = 0;
};

class SolutionFirst : public SolutionBase {
public:
    virtual void  paths(
            const std::vector<std::vector<int> >& triangle,
            std::vector<std::vector<int> >* paths) {
         std::vector<int> picked_path;
         paths_impl(triangle, &picked_path, 0, 0, paths);
    }

private:
    void paths_impl(
            const std::vector<std::vector<int> >& triangle,
            std::vector<int>* picked_path,
            int x,
            int y,
            std::vector<std::vector<int> >* paths) {
        picked_path->push_back(triangle[x][y]);

        if (x == static_cast<int>(triangle.size() - 1)) {
            paths->push_back(*picked_path);

            std::cout << "**************path**************" << std::endl;
            for (int i = 0; i < static_cast<int>(picked_path->size()); ++i) {
                std::cout << (*picked_path)[i] << std::endl;
            }
            return;
        }
        for (int i = 0; i <= 1; ++i) {
           paths_impl(triangle, picked_path, x + 1, y + i, paths);
           picked_path->pop_back();
        }
    }
};

}
