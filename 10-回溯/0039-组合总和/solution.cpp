// 39. 组合总和
// 原题：https://leetcode.cn/problems/combination-sum/
// 方法：固定候选起点，允许重复选当前数
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int,int)> dfs=[&](int start,int remain) {
            if(remain==0) { ans.push_back(path); return; }
            for(int i=start;i<(int)candidates.size() && candidates[i]<=remain;++i) {
                path.push_back(candidates[i]);
                // 仍从 i 开始，允许重复选，但不回头产生不同排列
                dfs(i,remain-candidates[i]);
                path.pop_back();
            }
        };
        dfs(0,target); return ans;
    }
};
