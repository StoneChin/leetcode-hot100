// 15. 三数之和
// 原题：https://leetcode.cn/problems/3sum/
// 方法：排序 + 固定一个数 + 双指针
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i + 2 < (int)nums.size(); ++i) {
            // 相同的第一个数只处理一次，避免重复三元组
            if (i && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) break;
            int l = i + 1, r = (int)nums.size() - 1;
            while (l < r) {
                long long sum = (long long)nums[i] + nums[l] + nums[r];
                if (sum < 0) ++l;
                else if (sum > 0) --r;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int a = nums[l], b = nums[r];
                    while (l < r && nums[l] == a) ++l;
                    while (l < r && nums[r] == b) --r;
                }
            }
        }
        return ans;
    }
};
