// 416. 分割等和子集
// 原题：https://leetcode.cn/problems/partition-equal-subset-sum/
// 方法：一维 0/1 背包可达性
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
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2) return false;
        int target=total/2;
        vector<bool> dp(target+1,false); dp[0]=true;
        // 倒序确保每个元素只被用一次
        for(int x:nums) for(int s=target;s>=x;--s) dp[s]=dp[s]||dp[s-x];
        return dp[target];
    }
};
