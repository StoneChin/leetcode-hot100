// 238. 除了自身以外数组的乘积
// 原题：https://leetcode.cn/problems/product-of-array-except-self/
// 方法：左右乘积分两趟计算
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
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int product = 1;
        for (int i = 0; i < (int)nums.size(); ++i) {
            // 先写左侧乘积，再把当前位置乘入累计值
            ans[i] = product;
            product *= nums[i];
        }
        product = 1;
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            ans[i] *= product;
            product *= nums[i];
        }
        return ans;
    }
};
