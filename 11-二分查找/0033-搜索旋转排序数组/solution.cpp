// 33. 搜索旋转排序数组
// 原题：https://leetcode.cn/problems/search-in-rotated-sorted-array/
// 方法：识别有序半边再二分
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
    int search(vector<int>& nums, int target) {
        int l=0,r=(int)nums.size()-1;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            // 先确认左半有序，再按数值范围判断目标在哪边
            if(nums[l]<=nums[mid]) {
                if(nums[l]<=target && target<nums[mid]) r=mid-1;
                else l=mid+1;
            } else {
                if(nums[mid]<target && target<=nums[r]) l=mid+1;
                else r=mid-1;
            }
        }
        return -1;
    }
};
