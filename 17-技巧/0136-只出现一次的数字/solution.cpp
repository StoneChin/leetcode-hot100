// 136. 只出现一次的数字
// 原题：https://leetcode.cn/problems/single-number/
// 方法：异或抵消成对数字
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
    int singleNumber(vector<int>& nums) {
        int ans=0;
        // 成对相同数互相抵消，最终只剩单独出现的数
        for(int x:nums) ans^=x;
        return ans;
    }
};
