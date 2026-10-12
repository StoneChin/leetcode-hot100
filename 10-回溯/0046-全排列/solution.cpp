// 46. 全排列
// 原题：https://leetcode.cn/problems/permutations/
// 方法：回溯枚举每个位置的选择
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path, used(nums.size());
        function<void()> dfs=[&]() {
            if(path.size()==nums.size()) { ans.push_back(path); return; }
            for(int i=0;i<(int)nums.size();++i) if(!used[i]) {
                used[i]=1; path.push_back(nums[i]);
                dfs();
                // 恢复本层选择，下一条排列仍可使用这个元素
                path.pop_back(); used[i]=0;
            }
        };
        dfs(); return ans;
    }
};
