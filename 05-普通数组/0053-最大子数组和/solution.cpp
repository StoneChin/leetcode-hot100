// 53. 最大子数组和
// 原题：https://leetcode.cn/problems/maximum-subarray/
// 方法：以当前位置结尾的最优和
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
    int maxSubArray(vector<int>& nums) {
        // end 必须以当前位置结尾；ans 可以结束在任何位置
        int end = nums[0], ans = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            end = max(nums[i], end + nums[i]); // 继续上一段，或者重新开始
            ans = max(ans, end);
        }
        return ans;
    }
};
