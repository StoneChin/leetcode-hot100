// 215. 数组中的第K个最大元素
// 原题：https://leetcode.cn/problems/kth-largest-element-in-an-array/
// 方法：大小为 k 的最小堆
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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> heap;
        for(int x:nums) {
            heap.push(x);
            // 淘汰最小值，始终只保留最大的 k 个元素
            if((int)heap.size()>k) heap.pop();
        }
        return heap.top();
    }
};
