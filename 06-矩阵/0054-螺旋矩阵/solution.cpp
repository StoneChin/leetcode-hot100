// 54. 螺旋矩阵
// 原题：https://leetcode.cn/problems/spiral-matrix/
// 方法：四条边界逐层收缩
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        vector<int> ans;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++j) ans.push_back(matrix[top][j]);
            ++top;
            for (int i = top; i <= bottom; ++i) ans.push_back(matrix[i][right]);
            --right;
            // 上边走完可能已经没有剩余行，防止重复访问
            if (top <= bottom) {
                for (int j = right; j >= left; --j) ans.push_back(matrix[bottom][j]);
                --bottom;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; --i) ans.push_back(matrix[i][left]);
                ++left;
            }
        }
        return ans;
    }
};
