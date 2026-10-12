// 78. 子集
// 原题：https://leetcode.cn/problems/subsets/
// 方法：每个数选或不选
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int)> dfs=[&](int i) {
            if(i==(int)nums.size()) { ans.push_back(path); return; }
            dfs(i+1); // 不选当前元素
            // 另一条分支选择当前元素，再处理剩余位置
            path.push_back(nums[i]);
            dfs(i+1);
            path.pop_back();
        };
        dfs(0); return ans;
    }
};
