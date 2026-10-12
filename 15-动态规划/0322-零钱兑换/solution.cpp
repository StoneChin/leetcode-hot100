// 322. 零钱兑换
// 原题：https://leetcode.cn/problems/coin-change/
// 方法：按金额计算最少硬币数
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
    int coinChange(vector<int>& coins, int amount) {
        // amount+1 表示不可达；金额 0 不需要硬币
        vector<int> dp(amount+1,amount+1); dp[0]=0;
        for(int x=1;x<=amount;++x)
            for(int c:coins) if(c<=x) dp[x]=min(dp[x],dp[x-c]+1);
        return dp[amount]>amount?-1:dp[amount];
    }
};
