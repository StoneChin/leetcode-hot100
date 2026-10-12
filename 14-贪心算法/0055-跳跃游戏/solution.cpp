// 55. 跳跃游戏
// 原题：https://leetcode.cn/problems/jump-game/
// 方法：维护最远可达下标
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
    bool canJump(vector<int>& nums) {
        int reach=0;
        for(int i=0;i<(int)nums.size();++i) {
            // 连当前位置都到不了，就无法继续扩展可达边界
            if(i>reach) return false;
            reach=max(reach,i+nums[i]);
        }
        return true;
    }
};
