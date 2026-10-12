// 152. 乘积最大子数组
// 原题：https://leetcode.cn/problems/maximum-product-subarray/
// 方法：同时维护最大与最小结尾乘积
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
    int maxProduct(vector<int>& nums) {
        int hi=nums[0],lo=nums[0],ans=nums[0];
        for(int i=1;i<(int)nums.size();++i) {
            int x=nums[i];
            int nextHi=max({x,hi*x,lo*x});
            // 旧最小乘积遇负数可能翻成最大，两个旧值都要保留
            int nextLo=min({x,hi*x,lo*x});
            hi=nextHi; lo=nextLo; ans=max(ans,hi);
        }
        return ans;
    }
};
