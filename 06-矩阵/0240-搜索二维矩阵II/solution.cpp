// 240. 搜索二维矩阵 II
// 原题：https://leetcode.cn/problems/search-a-2d-matrix-ii/
// 方法：从右上角逐行逐列排除
#include <algorithm>
#include <array>
#include <climits>
#include <deque>
#include <functional>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

// 力扣提供节点定义；本地检查时使用统一的测试定义。
#ifdef LOCAL_TEST
#include "../../tests/support.hpp"
#endif

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = 0, j = (int)matrix[0].size() - 1;
        while (i < (int)matrix.size() && j >= 0) {
            if (matrix[i][j] == target) return true;
            // 当前列下面都更大，排除这一列
            if (matrix[i][j] > target) --j;
            else ++i;
        }
        return false;
    }
};
