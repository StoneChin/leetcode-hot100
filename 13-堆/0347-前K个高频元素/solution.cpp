// 347. 前 K 个高频元素
// 原题：https://leetcode.cn/problems/top-k-frequent-elements/
// 方法：频率统计 + 频率桶
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int x:nums) ++count[x];
        // 桶下标是出现次数，最大不会超过数组长度
        vector<vector<int>> bucket(nums.size()+1);
        for(auto [x,c]:count) bucket[c].push_back(x);
        vector<int> ans;
        for(int c=nums.size();c>0;--c)
            for(int x:bucket[c]) {
                ans.push_back(x);
                if((int)ans.size()==k) return ans;
            }
        return ans;
    }
};
