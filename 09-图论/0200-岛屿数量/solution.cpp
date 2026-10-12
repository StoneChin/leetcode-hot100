// 200. 岛屿数量
// 原题：https://leetcode.cn/problems/number-of-islands/
// 方法：深度优先搜索淹没陆地
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
    void sink(vector<vector<char>>& g, int i, int j) {
        if (i < 0 || i >= (int)g.size() || j < 0 || j >= (int)g[0].size() || g[i][j] != '1') return;
        // 先标记，再递归邻居，避免两格来回访问
        g[i][j] = '0';
        sink(g,i-1,j); sink(g,i+1,j); sink(g,i,j-1); sink(g,i,j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int ans = 0;
        for (int i = 0; i < (int)grid.size(); ++i)
            for (int j = 0; j < (int)grid[0].size(); ++j)
                if (grid[i][j] == '1') { ++ans; sink(grid,i,j); }
        return ans;
    }
};
