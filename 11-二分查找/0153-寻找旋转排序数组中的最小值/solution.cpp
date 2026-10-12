// 153. 寻找旋转排序数组中的最小值
// 原题：https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/
// 方法：与右端点比较寻找旋转分界
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
    int findMin(vector<int>& nums) {
        int l=0,r=(int)nums.size()-1;
        while(l<r) {
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]) l=mid+1;
            // 右半有序时，mid 本身仍可能是最小值
            else r=mid;
        }
        return nums[l];
    }
};
