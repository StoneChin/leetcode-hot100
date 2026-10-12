// 35. 搜索插入位置
// 原题：https://leetcode.cn/problems/search-insert-position/
// 方法：寻找第一个不小于 target 的位置
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
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size();
        while(l<r) {
            int mid=l+(r-l)/2;
            if(nums[mid]<target) l=mid+1;
            // mid 可能恰好是第一个不小于目标的位置，必须保留
            else r=mid;
        }
        return l;
    }
};
