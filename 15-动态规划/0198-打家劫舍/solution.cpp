// 198. 打家劫舍
// 原题：https://leetcode.cn/problems/house-robber/
// 方法：当前房屋偷或不偷
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
    int rob(vector<int>& nums) {
        // two 是前两间最优值，one 是前一间最优值
        int two=0,one=0;
        for(int x:nums) { int next=max(one,two+x); two=one; one=next; }
        return one;
    }
};
