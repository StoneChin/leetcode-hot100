// 121. 买卖股票的最佳时机
// 原题：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
// 方法：维护历史最低价
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
    int maxProfit(vector<int>& prices) {
        // 只记录已经扫描过的最低价，保证买入不晚于卖出
        int low=INT_MAX,ans=0;
        for(int p:prices) { low=min(low,p); ans=max(ans,p-low); }
        return ans;
    }
};
