// 56. 合并区间
// 原题：https://leetcode.cn/problems/merge-intervals/
// 方法：按左端点排序后合并
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (const auto& p : intervals) {
            if (ans.empty() || p[0] > ans.back()[1]) ans.push_back(p);
            // 重叠时只扩展右界，不能被包含的短区间缩小
            else ans.back()[1] = max(ans.back()[1], p[1]);
        }
        return ans;
    }
};
