// 45. 跳跃游戏 II
// 原题：https://leetcode.cn/problems/jump-game-ii/
// 方法：按可达区间分层扩展
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
    int jump(vector<int>& nums) {
        int end=0,farthest=0,steps=0;
        for(int i=0;i+1<(int)nums.size();++i) {
            farthest=max(farthest,i+nums[i]);
            // 当前跳数这一层处理完，统一进入下一层
            if(i==end) { ++steps; end=farthest; }
        }
        return steps;
    }
};
