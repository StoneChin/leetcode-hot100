// 1. 两数之和
// 原题：https://leetcode.cn/problems/two-sum/
// 方法：一次遍历 + 哈希表
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
    vector<int> twoSum(vector<int>& nums, int target) {
        // 已扫描的数值 → 对应下标，保证两个下标不同
        unordered_map<int, int> seen;
        for (int i = 0; i < (int)nums.size(); ++i) {
            auto it = seen.find(target - nums[i]);
            if (it != seen.end()) return {it->second, i};
            seen[nums[i]] = i; // 只保存前面出现的元素
        }
        return {};
    }
};
