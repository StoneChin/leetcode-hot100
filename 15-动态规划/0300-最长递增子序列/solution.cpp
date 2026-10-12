// 300. 最长递增子序列
// 原题：https://leetcode.cn/problems/longest-increasing-subsequence/
// 方法：最小结尾数组 + 二分
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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(int x:nums) {
            // 找第一个 >=x 的结尾，相等时替换而不增加长度
            auto it=lower_bound(tails.begin(),tails.end(),x);
            if(it==tails.end()) tails.push_back(x);
            else *it=x;
        }
        return tails.size();
    }
};
