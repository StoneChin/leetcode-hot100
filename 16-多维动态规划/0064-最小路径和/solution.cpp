// 64. 最小路径和
// 原题：https://leetcode.cn/problems/minimum-path-sum/
// 方法：按行滚动计算最小代价
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
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty()) return 0;
        int m=grid.size(),n=grid[0].size();
        vector<int> dp(n);
        for(int i=0;i<m;++i) for(int j=0;j<n;++j) {
            if(i==0&&j==0) dp[j]=grid[i][j];
            else if(i==0) dp[j]=dp[j-1]+grid[i][j];
            else if(j==0) dp[j]+=grid[i][j];
            // 从上方与左方取最小成本，再计入当前格
            else dp[j]=min(dp[j],dp[j-1])+grid[i][j];
        }
        return dp[n-1];
    }
};
