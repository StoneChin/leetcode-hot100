// 73. 矩阵置零
// 原题：https://leetcode.cn/problems/set-matrix-zeroes/
// 方法：首行首列充当标记
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
    void setZeroes(vector<vector<int>>& a) {
        if (a.empty() || a[0].empty()) return;
        int m = a.size(), n = a[0].size();
        // 首行首列要作标记，先单独保存它们原本是否含零
        bool row = false, col = false;
        for (int j = 0; j < n; ++j) row |= a[0][j] == 0;
        for (int i = 0; i < m; ++i) col |= a[i][0] == 0;
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (a[i][j] == 0) a[i][0] = a[0][j] = 0;
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (a[i][0] == 0 || a[0][j] == 0) a[i][j] = 0;
        if (row) fill(a[0].begin(), a[0].end(), 0);
        if (col) for (int i = 0; i < m; ++i) a[i][0] = 0;
    }
};
