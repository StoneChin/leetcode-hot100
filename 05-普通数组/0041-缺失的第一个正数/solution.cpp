// 41. 缺失的第一个正数
// 原题：https://leetcode.cn/problems/first-missing-positive/
// 方法：原地把正数放回对应位置
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
    int firstMissingPositive(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            // 只归位合法正数；目标已有同值时停止，避免死循环
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                int target = nums[i] - 1; // 交换前保存目标位置
                swap(nums[i], nums[target]);
            }
        }
        for (int i = 0; i < n; ++i) if (nums[i] != i + 1) return i + 1;
        return n + 1;
    }
};
