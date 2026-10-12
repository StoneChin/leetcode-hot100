// 560. 和为 K 的子数组
// 原题：https://leetcode.cn/problems/subarray-sum-equals-k/
// 方法：前缀和 + 出现次数
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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> count;
        count[0] = 1; // 空前缀让从下标 0 开始的子数组也能被计数
        long long sum = 0;
        int ans = 0;
        for (int x : nums) {
            sum += x;
            auto it = count.find(sum - k);
            if (it != count.end()) ans += it->second;
            // 先查询再登记，避免把空子数组计入
            ++count[sum];
        }
        return ans;
    }
};
