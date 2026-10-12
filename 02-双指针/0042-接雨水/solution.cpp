// 42. 接雨水
// 原题：https://leetcode.cn/problems/trapping-rain-water/
// 方法：双指针维护两侧最高墙
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
    int trap(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1;
        int leftMax = 0, rightMax = 0, ans = 0;
        while (l <= r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            // 较低的最高墙一侧可以立刻确定水深
            if (leftMax <= rightMax) ans += leftMax - height[l++];
            else ans += rightMax - height[r--];
        }
        return ans;
    }
};
