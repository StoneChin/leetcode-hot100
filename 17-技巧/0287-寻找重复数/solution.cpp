// 287. 寻找重复数
// 原题：https://leetcode.cn/problems/find-the-duplicate-number/
// 方法：把数组看作带环链表
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
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        do { slow=nums[slow]; fast=nums[nums[fast]]; } while(slow!=fast);
        // 从起点与相遇点同步前进，找到环入口即重复值
        int p=0;
        while(p!=slow) { p=nums[p]; slow=nums[slow]; }
        return p;
    }
};
