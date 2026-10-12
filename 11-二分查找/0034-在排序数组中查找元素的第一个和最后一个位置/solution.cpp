// 34. 在排序数组中查找元素的第一个和最后一个位置
// 原题：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
// 方法：二分左右边界
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
    vector<int> searchRange(vector<int>& nums, int target) {
        auto boundary=[&](bool strict) {
            int l=0,r=nums.size();
            while(l<r) {
                int mid=l+(r-l)/2;
                if(nums[mid]<target || (strict && nums[mid]==target)) l=mid+1;
                else r=mid;
            }
            return l;
        };
        int first=boundary(false);
        if(first==(int)nums.size()||nums[first]!=target) return {-1,-1};
        // 第一个严格大于目标的位置减一，就是最后一个目标
        return {first,boundary(true)-1};
    }
};
