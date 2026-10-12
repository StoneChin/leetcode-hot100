// 279. 完全平方数
// 原题：https://leetcode.cn/problems/perfect-squares/
// 方法：枚举最后一个平方数
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
    int numSquares(int n) {
        vector<int> dp(n+1,n+1); dp[0]=0;
        for(int x=1;x<=n;++x)
            // 枚举最后一个平方数，剩余金额状态已经算好
            for(int j=1;j*j<=x;++j) dp[x]=min(dp[x],dp[x-j*j]+1);
        return dp[n];
    }
};
