// 70. 爬楼梯
// 原题：https://leetcode.cn/problems/climbing-stairs/
// 方法：只保留前两个状态
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
    int climbStairs(int n) {
        // 分别保存 f(0)、f(1)，每轮滚动为相邻两项
        int a=1,b=1;
        for(int i=2;i<=n;++i) { int next=a+b; a=b; b=next; }
        return b;
    }
};
