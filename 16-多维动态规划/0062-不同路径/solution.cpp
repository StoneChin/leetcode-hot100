// 62. 不同路径
// 原题：https://leetcode.cn/problems/unique-paths/
// 方法：按行滚动计算路径数
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
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        // 更新前 dp[j] 是上方，dp[j-1] 已经是本行左方
        for(int i=1;i<m;++i) for(int j=1;j<n;++j) dp[j]+=dp[j-1];
        return dp[n-1];
    }
};
