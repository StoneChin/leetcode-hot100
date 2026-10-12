// 169. 多数元素
// 原题：https://leetcode.cn/problems/majority-element/
// 方法：Boyer–Moore 投票抵消
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
    int majorityElement(vector<int>& nums) {
        int candidate=0,votes=0;
        for(int x:nums) {
            // 此前候选已被抵消完，用当前元素重新开始投票
            if(votes==0) candidate=x;
            votes+=(x==candidate?1:-1);
        }
        return candidate;
    }
};
