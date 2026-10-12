// 11. 盛最多水的容器
// 原题：https://leetcode.cn/problems/container-with-most-water/
// 方法：两端向内移动短板
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
    int maxArea(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1, ans = 0;
        // 宽度逐渐减小，每轮舍弃当前短板
        while (l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) ++l; // 只有换掉短板才可能改善容量
            else --r;
        }
        return ans;
    }
};
