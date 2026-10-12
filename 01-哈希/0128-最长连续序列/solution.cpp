// 128. 最长连续序列
// 原题：https://leetcode.cn/problems/longest-consecutive-sequence/
// 方法：哈希集合寻找连续段起点
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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int x : s) {
            // 只从连续段的第一个数向后展开
            if (x != INT_MIN && s.count(x - 1)) continue;
            int y = x, len = 1;
            while (y != INT_MAX && s.count(y + 1)) { ++y; ++len; }
            ans = max(ans, len);
        }
        return ans;
    }
};
