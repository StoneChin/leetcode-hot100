// 283. 移动零
// 原题：https://leetcode.cn/problems/move-zeroes/
// 方法：读写双指针
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
    void moveZeroes(vector<int>& nums) {
        // 下一项非零元素应该写入的下标
        int write = 0;
        for (int x : nums) if (x != 0) nums[write++] = x;
        // 前半段已有全部非零数，剩余位置统一补零
        fill(nums.begin() + write, nums.end(), 0);
    }
};
