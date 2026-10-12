// 48. 旋转图像
// 原题：https://leetcode.cn/problems/rotate-image/
// 方法：转置后反转每一行
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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            // 只交换对角线的一侧，每对位置交换一次
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
        for (auto& row : matrix) reverse(row.begin(), row.end());
    }
};
